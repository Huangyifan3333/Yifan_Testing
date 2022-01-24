/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package elec366_lab_04;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.lang.AssertionError;
import java.util.ArrayList;
import java.util.Vector;
import java.util.concurrent.Semaphore;

/**
 *
 * @author yifan
 */
public class Client_Game {

    /**
     *
     */
    public static Vector<String> playNameList = new Vector();

    private static GUI_Game UI = new GUI_Game();
    private static Thread th = null;// global thread
    private static Socket clientSocket = null;
    private static BufferedReader bufferIn = null;
    private static InputStreamReader inputStream = null;
    private static DataOutputStream outputStream = null;
    private static String receivingMsg = "";
    private static String clientName = "";
    private static String forwardName = "null";

    private static Semaphore mutex = new Semaphore(1);// mute to protect accessing client socket
    private static Semaphore mutexFlag1 = new Semaphore(1);//to control toggling Client UI 
    //private static Semaphore mutexFlag2 = new Semaphore(0);
    // private static Semaphore mutexFlag2 = new Semaphore(0);//not used so far
    private static boolean flag;//flag to set condition for togging Client UI

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //draw client UI
        Client_Game.UI.drawClient();

        //listen to button click
        Client_Game.clickButton_Logon();
        Client_Game.clickButton_Play();
        Client_Game.clickFrame_Close();
        Client_Game.clickButton_Accept();
        Client_Game.clickButton_Refuse();
        Client_Game.clickButton_ROCK();
        Client_Game.clickButton_PAPER();
        Client_Game.clickButton_SCISSOR();
    }

    //method to implement click connect button
    private static void clickButton_Logon() {
        UI.getButton_connect().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //connect:  open the socket, ,start thread, send log in msg flag by -Login , update client UI
                //disconnect:  send msg to server flag by -Logout, stop the thread, close client socket, update the client UI 
                try {
                    if (Client_Game.UI.getConnectionStatus() == "Log in") {//to connect socket

                        Client_Game.clientName = Client_Game.UI.getClientName().toString().trim();
                        printMsg("clientName is: " + clientName);

                        //catch exception if client name is empty
                        assert (!Client_Game.clientName.matches(""));
                        if (Client_Game.clientName.matches("")) {
                            throw new AssertionError();
                        }

                        //open a client socket and establish connection with server
                        Client_Game.clientSocket = new Socket("localhost", 5000);//local IP address:127.0.0.1, server port:5000
                        //test
                        Client_Game.printMsg("client socket opened with local port: " + Client_Game.clientSocket.getLocalPort() + "\n");

                        //start clientRun thread
                        Client_Game.clientRun();

                        //intantiate output stream
                        Client_Game.outputStream = new DataOutputStream(Client_Game.clientSocket.getOutputStream());

                        String msg = "-Login;" + Client_Game.clientName + ";" + Client_Game.forwardName + "\n";// format is -Login;userName;forwardName
                        Client_Game.outputStream.writeBytes(msg);//send log in msg to clientProcess 
                        //Client_Game.forwardName = "null";//clear forward name
                        printMsg(msg);

                        //to do: implement mutex signal and wait 
                        Client_Game.flag = false;//set falg false
                        //wait for 2 seconds to receive the in coming message.
                        int timer = 0;
                        while (Client_Game.flag == false) {
                            //time out 2 second
                            Thread.sleep(1000);
                            timer++;
                            if (timer > 2) {
                                break;
                            }
                        }

                        Client_Game.mutexFlag1.acquire();
                        if (Client_Game.flag == true) {//update client UI if received the message from server
                            //toggle connect button and PlayingUI                      
                            Client_Game.UI.toggleLogonButton_Client(true);

                        } else {//close the socket and thread if not received message from server
                            Client_Game.clientSocket.close();
                            //stop clientRun thread
                            Client_Game.clientStop();

                        }
                        Client_Game.mutexFlag1.release();

                    } else {//log out and disconnect socket
                        if (!Client_Game.clientSocket.isClosed()) {
                            Client_Game.flag = false;//set flag false

                            //send log out msg
                            String msg = "-Logout;" + Client_Game.clientName + ";" + Client_Game.forwardName + "\n";
                            Client_Game.outputStream.writeBytes(msg);//output stream was opened on connecting
                            Client_Game.forwardName = "null";//clear forward name

                            mutex.acquire();
                            //close client socket
                            Client_Game.clientSocket.close();
                            mutex.release();
                            //stop clientRun thread
                            Client_Game.clientStop();

                            //update client UI
                            Client_Game.UI.toggleLogonButton_Client(false);

                        }

                    }
                } catch (Exception ex1) {
                    Client_Game.UI.setExceptionMsg(ex1.toString().trim());
                } catch (AssertionError ex2) {
                    Client_Game.UI.setExceptionMsg("Exception: Client name can not be empty!");
                }
            }
        });
    }

    //method to implement the click play button
    private static void clickButton_Play() {
        Client_Game.UI.getButton_play().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //to do get text msg from UI, send to outputstream conecting with server
                try {

                    String msg = "";
                    if (Client_Game.UI.getPlayStatus().matches("Play")) {//send play request msg
                        Client_Game.forwardName = Client_Game.UI.getPlayWithName();//get name from drop list

                        assert (!Client_Game.forwardName.matches("null"));//catch exception on empty sending message
                        if (Client_Game.forwardName.matches("null")) {
                            throw new AssertionError("playName is empty");
                        }

                        Client_Game.UI.togglePlayButton_Client(true);//update play UI, pop up 3 play buttons

                        //format is  "-Play;clientUserName;PlayWithName"
                        msg = "-Play;" + Client_Game.clientName + ";" + Client_Game.forwardName + "\n";
                    } else {//send stop playing msg
                        Client_Game.UI.togglePlayButton_Client(false);
                        //format is  "-Stop;clientUserName;PlayWithName"
                        msg = "-Stop;" + Client_Game.clientName + ";" + Client_Game.forwardName + "\n";
                        printMsg("forward name: " + Client_Game.forwardName);
                    }

                    Client_Game.outputStream.writeBytes(msg);//send play request to server Game Process

                } catch (Exception ex1) {
                    Client_Game.UI.setExceptionMsg(ex1.toString().trim());
                } catch (AssertionError ex2) {
                    Client_Game.UI.setExceptionMsg(ex2.toString());
                }

            }
        });
    }

    private static void clickFrame_Close() {
        Client_Game.UI.getClientFrame().addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent we) {
                // to fo get client User name, send msg flagged by -Logout to server, update UI if possible
                try {
                    if (Client_Game.clientSocket == null || Client_Game.clientSocket.isClosed()) {

                        //update client UI
                        Client_Game.UI.toggleLogonButton_Client(false);
                        Client_Game.UI.togglePlayButton_Client(false);
                        System.exit(0);

                    } else if (!Client_Game.clientSocket.isClosed()) {
                        //send log out msg
                        String msg = "-Logout;" + Client_Game.clientName + ";" + Client_Game.forwardName + "\n";
                        Client_Game.outputStream.writeBytes(msg);//output stream was opened on connecting
                        Client_Game.forwardName = "null";//clear forward name

                        mutex.acquire();
                        //close client socket
                        Client_Game.clientSocket.close();
                        mutex.release();

                        //stop clientRun thread
                        Client_Game.clientStop();

                        System.exit(0);
                    }
                } catch (Exception ex1) {
                    Logger.getLogger(Client_Game.class.getName()).log(Level.SEVERE, null, ex1);
                    Client_Game.UI.setExceptionMsg(ex1.toString().trim());
                }
            }
        });
    }

    //implement ROCK button click
    private static void clickButton_ROCK() {
        Client_Game.UI.getButton_ROCK().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                try {
                    if (Client_Game.UI.getButton_ROCK().getText().matches("ROCK")) {
                        String msg = "-Rock;" + Client_Game.clientName + ";" + Client_Game.forwardName + "\n";
                        Client_Game.outputStream.writeBytes(msg);

                        //disable the 3 game choices
                        Client_Game.UI.setRockPaperScissorEnable(false);

                        Client_Game.forwardName = "null";//clear forward name
                    }
                } catch (Exception ex1) {
                    Logger.getLogger(Client_Game.class.getName()).log(Level.SEVERE, null, ex1);
                    Client_Game.UI.setExceptionMsg(ex1.toString().trim());
                }
            }
        });
    }

    //implement PAPER button click
    private static void clickButton_PAPER() {
        Client_Game.UI.getButton_PAPER().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                try {
                    if (Client_Game.UI.getButton_PAPER().getText().matches("PAPER")) {
                        String msg = "-Paper;" + Client_Game.clientName + ";" + Client_Game.forwardName + "\n";
                        Client_Game.outputStream.writeBytes(msg);

                        //disable the 3 game choices
                        Client_Game.UI.setRockPaperScissorEnable(false);

                        Client_Game.forwardName = "null";//clear forward name
                    }
                } catch (Exception ex1) {
                    Logger.getLogger(Client_Game.class.getName()).log(Level.SEVERE, null, ex1);
                    Client_Game.UI.setExceptionMsg(ex1.toString().trim());
                }
            }
        });
    }

    //implement SCISSOR button click
    private static void clickButton_SCISSOR() {
        Client_Game.UI.getButton_SCISSOR().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                try {
                    if (Client_Game.UI.getButton_SCISSOR().getText().matches("SCISSOR")) {
                        String msg = "-Scissor;" + Client_Game.clientName + ";" + Client_Game.forwardName + "\n";
                        Client_Game.outputStream.writeBytes(msg);

                        //disable the 3 game choices
                        Client_Game.UI.setRockPaperScissorEnable(false);

                        Client_Game.forwardName = "null";//clear forward name
                    }
                } catch (Exception ex1) {
                    Logger.getLogger(Client_Game.class.getName()).log(Level.SEVERE, null, ex1);
                    Client_Game.UI.setExceptionMsg(ex1.toString().trim());
                }
            }
        });
    }

    //implement accept button click
    private static void clickButton_Accept() {
        Client_Game.UI.getButton_Accept().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                try {
                    if (Client_Game.UI.getButton_Accept().getText().matches("Accept")) {
                        String msg = "-Accept;" + Client_Game.clientName + ";" + Client_Game.forwardName + "\n";
                        Client_Game.outputStream.writeBytes(msg);

                        //pop up 3 game choice buttons
                        Client_Game.UI.togglePlayButton_Client(true);
                        Client_Game.UI.togglePlayUI_Client(true);
                        Client_Game.UI.setAcptRefusVisible(false);
                    }
                } catch (Exception ex1) {
                    Logger.getLogger(Client_Game.class.getName()).log(Level.SEVERE, null, ex1);
                    Client_Game.UI.setExceptionMsg(ex1.toString().trim());
                }
            }
        });
    }

    //implement refuse button click
    private static void clickButton_Refuse() {
        Client_Game.UI.getButton_Refuse().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                try {
                    if (Client_Game.UI.getButton_Refuse().getText().matches("Refuse")) {
                        String msg = "-Refuse;" + Client_Game.clientName + ";" + Client_Game.forwardName + "\n";
                        Client_Game.outputStream.writeBytes(msg);
                        //Client_Game.forwardName = "null";//clear forward name

                        //hide 3 game choice buttons
                        Client_Game.UI.togglePlayButton_Client(false);
                    }
                } catch (Exception ex1) {
                    Logger.getLogger(Client_Game.class.getName()).log(Level.SEVERE, null, ex1);
                    Client_Game.UI.setExceptionMsg(ex1.toString().trim());
                }
            }
        });
    }

    private static void clientRun() {

        Client_Game.th = new Thread(new Runnable() {
            @Override
            public void run() {
                //listen to the server by client socket, incoming message is flagged by -ACK, -Request, -Result and -Reject
                //append msg to UI by each msg flag
                try {
                    //flush the Input Stream
                    Client_Game.inputStream = new InputStreamReader(Client_Game.clientSocket.getInputStream());
                    //put in buffer
                    Client_Game.bufferIn = new BufferedReader(Client_Game.inputStream);
                    while (!Client_Game.clientSocket.isClosed()) {
                        mutex.acquire();
                        //Thread.sleep(1000);
                        if (!Client_Game.clientSocket.isClosed()) {
                            Client_Game.receivingMsg = Client_Game.bufferIn.readLine();
                        }
                        mutex.release();
                        
                        
                        if (Client_Game.receivingMsg == null) {

                            printMsg("null message");
                            throw new Exception();

                        } else if (Client_Game.receivingMsg.startsWith("-MSGACK")) {//receive connection ACK
                            //update flag to control logon  UI 
                            Client_Game.mutexFlag1.acquire();
                            Client_Game.flag = true;
                            Client_Game.mutexFlag1.release();

                            //to test only,print in console
                            printMsg(Client_Game.receivingMsg);
                            //String[] token = Client_Game.receivingMsg.split(";");

                        } else if (Client_Game.receivingMsg.startsWith("-MSGError")) {
                            //to update UI for duplicated log in User name
                            Client_Game.mutexFlag1.acquire();
                            Client_Game.flag = false;
                            Client_Game.mutexFlag1.release();

                            //to test only,print in console
                            printMsg(Client_Game.receivingMsg);
                            //String[] token = Client_Game.receivingMsg.split(";");

                        } else if (Client_Game.receivingMsg.startsWith("-MSGRequest")) {//receive play request 
                            //show accpet and refuse button 
                            Client_Game.UI.setAcptRefusVisible(true);

                            String[] token = Client_Game.receivingMsg.split(";");
                            if (token.length > 1) {
                                //get sender name which will be added to forwardname, either accept or refuse
                                String playName = token[1].trim();//get sender username

                                Client_Game.forwardName = playName;

                                //to test only,print in console
                                printMsg(Client_Game.receivingMsg);

                            }

                        } else if (Client_Game.receivingMsg.startsWith("-MSGResult")) {
                            //set result msg 
                            String[] token = Client_Game.receivingMsg.split(";");
                            if (token.length > 1) {

                                //set result msg in UI
                                for (int i = 1; i < token.length; i++) {//msg starting from 2nd index 
                                    Client_Game.UI.setResultMsg(token[i]);//set line by line

                                }
                            }

                            Client_Game.forwardName = "null";//clear forward name

                            //to test only,print in console
                            printMsg(Client_Game.receivingMsg);

                        } else if (Client_Game.receivingMsg.startsWith("-MSGRefuse")) {//play partner refused playing the game
                            //set Refuse playing msg
                            String[] token = Client_Game.receivingMsg.split(";");
                            if (token.length > 1) {
                                String playName = token[1].trim();

                                Client_Game.UI.setResultMsg(playName + " refused playing game!");
                            }
                            //hide 3 Game buttons, go back initial UI selecting play partner 
                            Client_Game.UI.togglePlayUI_Client(false);

                            //to test only,print in console
                            printMsg(Client_Game.receivingMsg);

                        } else if (Client_Game.receivingMsg.startsWith("-MSGAccept")) {
                            //show 3 Game buttons, ready to play
                            Client_Game.UI.togglePlayUI_Client(true);

                            //set accept playing msg
                            String[] token = Client_Game.receivingMsg.split(";");
                            if (token.length > 1) {
                                String playName = token[1].trim();

                                Client_Game.UI.setResultMsg(playName + " accepted playing game!");
                            }

                            //to test only,print in console
                            printMsg(Client_Game.receivingMsg);

                        } else if (Client_Game.receivingMsg.startsWith("-MSGLogin")) {
                            //update playwith drop down menu
                            String[] token = Client_Game.receivingMsg.split(";");

                            if (token.length > 1) {
                                String playName = token[1].trim();

                                if (!Client_Game.clientName.matches(playName)) {
                                    //update playwith drop down menu
                                    flag = true;
                                    for (String name : Client_Game.playNameList) {
                                        if (playName.matches(name)) {
                                            flag = false;//name already in the list
                                        }
                                    }
                                    if (flag == true) {
                                        //add the playname list if name is not in the list 
                                        Client_Game.playNameList.add(playName);
                                    }
                                }
                            }
                            //to test only,print in console
                            //printMsg(Client_Game.receivingMsg);

                        } else if (Client_Game.receivingMsg.startsWith("-MSGLogout")) {
                            //update playwith drop down menu
                            String[] token = Client_Game.receivingMsg.split(";");

                            if (token.length > 1) {
                                String playName = token[1].trim();

                                //update playwith drop down menu
                                if (!Client_Game.clientName.matches(playName)) {
                                    flag = false;
                                    for (String name : Client_Game.playNameList) {
                                        if (playName.matches(name)) {
                                            flag = true;//name already in the list
                                        }
                                    }
                                    if (flag == true) {
                                        //remove the playname list 
                                        Client_Game.playNameList.remove(playName);
                                    }

                                }
                                //to test only,print in console
                                printMsg(Client_Game.receivingMsg);

                            }
                        } else if (Client_Game.receivingMsg.startsWith("-MSGPlay")) {
                            //update play with drop down menu
                            String[] token = Client_Game.receivingMsg.split(";");

                            if (token.length > 1) {
                                String playName = token[1].trim();

                                //update playwith drop down menu
                                if (!Client_Game.clientName.matches(playName)) {
                                    flag = false;
                                    for (String name : Client_Game.playNameList) {
                                        if (playName.matches(name)) {
                                            flag = true;//name already in the list
                                        }
                                    }
                                    if (flag == true) {
                                        //remove the playname list 
                                        Client_Game.playNameList.remove(playName);
                                    }
                                }
                            }
                            //to test only,print in console
                            printMsg(Client_Game.receivingMsg);

                        } else if (Client_Game.receivingMsg.startsWith("-MSGStop")) {
                            //update playwith drop down menu
                            String[] token = Client_Game.receivingMsg.split(";");
                            if (token.length > 1) {
                                String playName = token[1].trim();

                                //update playwith drop down menu
                                if (!Client_Game.clientName.matches(playName)) {
                                    flag = true;
                                    for (String name : Client_Game.playNameList) {
                                        if (playName.matches(name)) {
                                            flag = false;//name already in the list
                                        }
                                    }
                                    if (flag == true) {
                                        //add the playname list if name is not in the list 
                                        Client_Game.playNameList.add(playName);
                                    }
                                }
                            }
                            //to test only,print in console
                            printMsg(Client_Game.receivingMsg);

                        }

                        Client_Game.receivingMsg = "";//clear message
                        //Thread.sleep(1000);
                    }
                } catch (Exception ex) {
                    Logger.getLogger(Client_Game.class.getName()).log(Level.SEVERE, null, ex);
                    printMsg("Exception on logout null message");
                }
            }
        });
        th.start();
    }

    private static void clientStop() {//stop the thread
        try {
            th.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(Client_Game.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    //printer
    private static void printMsg(String e) {
        System.out.println(e);
    }

}
