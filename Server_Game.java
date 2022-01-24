/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package elec366_lab_04;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Vector;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author yifan
 */
public class Server_Game {

    private static GUI_Game UI = new GUI_Game();

    public static ArrayList<GameProcess> gameProcessList = new ArrayList();
    //playnamelist to be broadcasted to all the clients, so as to update the playname drop down menu in client UI
    public static ArrayList<String> playNameList = new ArrayList();

    private static int processID = 0;
    public static ServerSocket serverSocket = null;
    private static Socket connectingSocket = null;
    private static BufferedReader bufferIn = null;
    private static DataOutputStream outputStream = null;
    private static InputStreamReader inputStream = null;
    private static String sendingMsg = "";//msg for broadcasting

    private static Semaphore mutex = new Semaphore(1);//mutex to protect accessing sendingMsg string

    private static Thread th1 = null;
    private static Thread th2 = null;
    private static Thread th3 = null;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            // code application logic here
            Server_Game.UI.drawServer();

            Server_Game.serverRun();

            Thread threadEngine = new Thread(GameEngine.INSTANCE);
            threadEngine.start();
            
            Server_Game.clickFrame_Close();
            //stop the thread
            threadEngine.join();

        } catch (InterruptedException ex) {
            Logger.getLogger(Server_Game.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    /**
     *
     */
    public static void serverRun() {

        try {
            //instantiate the server with port at "5000"
            Server_Game.serverSocket = new ServerSocket(5000);
        } catch (IOException ex) {
            Logger.getLogger(Server_Game.class.getName()).log(Level.SEVERE, null, ex);
        }

        /**
         * * Thread 1 **
         */
        //thread to accept connection from the Client based on clientName and start a new GameProcess thread and add to the process List
        Server_Game.th1 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    while (!Server_Game.serverSocket.isClosed()) {

                        //serve accepts the connection from client
                        Server_Game.connectingSocket = Server_Game.serverSocket.accept();
                        printMsg("Connection Socket Accepted from Port: " + connectingSocket.getPort());
                        //flush input stream
                        Server_Game.inputStream = new InputStreamReader(Server_Game.connectingSocket.getInputStream());
                        //flush receiving buffer 
                        Server_Game.bufferIn = new BufferedReader(Server_Game.inputStream);

                        //get receiving message
                        String receivingMsg = bufferIn.readLine();
                        Server_Game.printMsg("ReceivingMsg: " + receivingMsg);//test

                        //check the client user Name
                        if (receivingMsg.startsWith("-Login")) {
                            //extract the UserName from input String Msg
                            String sourceName = receivingMsg.split(";")[1].trim();

                            if (Server_Game.gameProcessList.size() == 0) {//the first client log in
                                //instantiate new GameProcess
                                GameProcess process = new GameProcess(Server_Game.processID++, sourceName, Server_Game.connectingSocket);

                                //start this GameProcess
                                process.start();

                                //add new client process to GameProcess array list
                                Server_Game.gameProcessList.add(process);

                                Server_Game.mutex.acquire();
                                Server_Game.playNameList.add(sourceName);
                                //update sendingMSg
                                //Server_Game.sendingMsg = "-MSGLogin;" + sourceName + ";" + "logged in" + "\n";
                                Server_Game.mutex.release();

                                String msg = "-MSGACK;" + sourceName + ";" + "logged in" + "\n";
                                //send ack msg to login Client only
                                Server_Game.outputStream = new DataOutputStream(Server_Game.connectingSocket.getOutputStream());
                                Server_Game.outputStream.writeBytes(msg);
                            } else {//starting from the secomd client log in
                                boolean flag = true;//flag to indicate accepting userName to login and

                                //check client user sourceName in the list
                                for (GameProcess GP : Server_Game.gameProcessList) {

                                    //refuse create new Client Process if found this UserName is already in List
                                    if (GP.getUserName().matches(sourceName)) {
                                        printMsg("repeating sourceName is :" + sourceName);//test
                                        flag = false;

                                        //update Error MSg
                                        String msg = "-MSGError;" + sourceName + ";" + "already logged in" + "\n";
                                        //instiate the output stream based on the current clientProcess Socket
                                        Server_Game.outputStream = new DataOutputStream(Server_Game.connectingSocket.getOutputStream());
                                        //send error msg to rejecting Client only
                                        Server_Game.outputStream.writeBytes(msg);
                                        Server_Game.connectingSocket.close();//close this connecting socket on server

                                    }
                                }
                                if (flag == true) {
                                    //accept connection and create new client process
                                    //client process ID increments once it accepts a new client conection
                                    //instantiate new GameProcess
                                    GameProcess process = new GameProcess(Server_Game.processID++, sourceName, Server_Game.connectingSocket);

                                    //start this process
                                    process.start();

                                    //add new client process to GameProcess array list
                                    Server_Game.gameProcessList.add(process);

                                    printMsg("Process size is: " + Server_Game.gameProcessList.size());//test

                                    Server_Game.mutex.acquire();
                                    Server_Game.playNameList.add(sourceName);
                                    //Server_Game.sendingMsg = "-MSGLogin;" + sourceName + ";" + "logged in" + "\n";
                                    Server_Game.mutex.release();

                                    //update ack sendingMSg
                                    String msg = "-MSGACK;" + sourceName + ";" + "logged in" + "\n";
                                    //send ack msg to login Client only
                                    Server_Game.outputStream = new DataOutputStream(Server_Game.connectingSocket.getOutputStream());
                                    Server_Game.outputStream.writeBytes(msg);

                                }
                            }
                        }

                        Thread.sleep(1000);
                    }

                } catch (IOException ex) {
                    Logger.getLogger(Server_Game.class.getName()).log(Level.SEVERE, null, ex);
                } catch (InterruptedException ex) {
                    Logger.getLogger(Server_Game.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });

        Server_Game.th1.start();
        /**
         * * Thread 2 **
         */
        //Thread to broadcast login msg to all clients and update the connection status on Server
        Server_Game.th2 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    while (!Server_Game.serverSocket.isClosed()) {
                        //update the Server connection status 
                        if (!Server_Game.gameProcessList.isEmpty()) { //printMsg("test1");
                            String connectionStatus = String.valueOf(Server_Game.gameProcessList.size()) + " ClientsConnected";
                            Server_Game.UI.toggleConnectionStatus_Server(true, connectionStatus);
                        } else { //printMsg("test2");
                            Server_Game.UI.toggleConnectionStatus_Server(false, "No Clients Connected ");
                        }

                        Server_Game.mutex.acquire();//mutex protect the data of sendingMsg

                        //broadcast User login Msg to all clients 
                        if (Server_Game.sendingMsg == "") {
                            for (GameProcess GP : Server_Game.gameProcessList) {
                                if (!GP.getConnectingSocket().isClosed()) {
                                    //instiate the output stream based on each clientProcess Socket
                                    Server_Game.outputStream = new DataOutputStream(GP.getConnectingSocket().getOutputStream()); //send msg to each client

                                    //send all the play names to each previously log in client
                                    for (String namelist : Server_Game.playNameList) {
                                        Server_Game.sendingMsg = "-MSGLogin;" + namelist + ";" + "logged in" + "\n";

                                        Server_Game.outputStream.writeBytes(Server_Game.sendingMsg);
                                    }
                                }

                            }
                        }
                        //clear sending message after broadcasting 
                        Server_Game.sendingMsg = "";

                        Server_Game.mutex.release();//release mutex

                        Thread.sleep(1000);
                    }
                } catch (InterruptedException | IOException ex) {
                    Logger.getLogger(Server_Game.class.getName()).log(Level.SEVERE,
                            null, ex);
                }
            }
        }
        );
        Server_Game.th2.start();

        /**
         * * Thread 3 **
         */
        ///Thread to stop the running CLientProcess thread of which has been removed from process list
        // must excute this part before processs been removed
        Server_Game.th3 = new Thread(
                new Runnable() {
            @Override
            public void run() {
                while (!Server_Game.serverSocket.isClosed()) {
                    try {

                        if (GameProcess.threadStopPosition >= 0) {
                            //join the GameProcess thread
                            Server_Game.gameProcessList.get(GameProcess.threadStopPosition).join();
                        }
                        //release mutex2 at for removing the CLientProcess from the list in GameProcess 
                        GameProcess.mutex2.release();

                        Thread.sleep(1000);
                        GameProcess.threadStopPosition = -1;//reset this shared value

                        //wait at mutex1, till released by signal at GameProcess thread
                        GameProcess.mutex1.acquire();

                    } catch (InterruptedException ex) {
                        Logger.getLogger(Server_Game.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }

            }
        }
        );
        Server_Game.th3.start();
    }

    public static void serverStop() {
        try {
            Server_Game.th1.join();
            Server_Game.th2.join();
            Server_Game.th3.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(Server_Game.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static void clickFrame_Close() {
        Server_Game.UI.getClientFrame().addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent we) {
                // to fo get client User name, send msg flagged by -Logout to server, update UI if possible
                try {
                    if (!Server_Game.serverSocket.isClosed()) {
                        Server_Game.serverSocket.close();
                        Server_Game.serverStop();

                    } else {
                        //do nothing
                    }
                    System.exit(0);
                } catch (Exception ex1) {
                    Logger.getLogger(Server_Game.class.getName()).log(Level.SEVERE, null, ex1);
                    Server_Game.UI.setExceptionMsg(ex1.toString().trim());
                }
            }
        });
    }

    //printer
    public static void printMsg(String e) {
        System.out.println(e);
    }

}
