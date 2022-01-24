/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package elec366_lab_04;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.Iterator;
import java.util.concurrent.Semaphore;

/**
 *
 * @author yifan
 */
public class GameProcess extends Thread {

    //data
    private int PID = 0;
    private String userName = "";
    private Socket connectingSocket = null;
    private String gameChoice = "null";

    private BufferedReader bufferIn = null;
    private DataOutputStream outputStream = null;
    private InputStreamReader inputSteam = null;

    //this int indicate which ClientProcess thread should be stop after being removed from the Process List
    public static int threadStopPosition = -1;

    //mutex to protect accessing threadStopPostion data 
    //removing Process must wait until Process thread been stopped!
    public static Semaphore mutex1 = new Semaphore(0);
    public static Semaphore mutex2 = new Semaphore(0);

    //constructor
    /**
     *
     * @param count
     * @param name
     * @param connectSocket
     */
    public GameProcess(int count, String name, Socket connectSocket) {
        this.PID = count;
        this.userName = name;
        this.connectingSocket = connectSocket;

    }

    //getter and settter
    public int getPID() {
        return PID;
    }

    public void setPID(int PID) {
        this.PID = PID;
    }

    public String getUserName() {
        return userName;
    }

    public String getGameChoice() {
        return gameChoice;
    }

    public void setGameChoice(String gameChoice) {
        this.gameChoice = gameChoice;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public Socket getConnectingSocket() {
        return connectingSocket;
    }

    public void setConnectingSocket(Socket connectingSocket) {
        this.connectingSocket = connectingSocket;
    }

    public void clientProcessRun() {
        try {

            while (!this.connectingSocket.isClosed()) {
                //flush input stream
                this.inputSteam = new InputStreamReader(this.connectingSocket.getInputStream());
                //flush receiving buffer 
                this.bufferIn = new BufferedReader(this.inputSteam);
                //keep reading message
                String receivingMsg = this.bufferIn.readLine();

                if (receivingMsg.startsWith("-Logout")) {//client disconnected or client seesion closed
                    //Server_Game.printMsg("test: client " + this.userName +" sent -Log out");//test
                    Server_Game.printMsg("Logout msg: " + receivingMsg);
                    String[] token = receivingMsg.split(";");

                    int position = -1;
                    if (token.length > 0) {
                        String senderName = token[1].trim();//get sender username
                        String forwardName = token[2].trim();//get the forward userName

                        if (!this.userName.matches(senderName)) {
                            printMsg("userName: " + this.userName + ", senderName: " + senderName);
                            throw new AssertionError("userName is not same as senderName");
                        }
                        // to test only
                        if (forwardName.matches("null")) {
                            printMsg("forward Name is null!");
                        }

                        for (int i = 0; i < Server_Game.gameProcessList.size(); i++) {
                            if (Server_Game.gameProcessList.get(i).getPID() == this.PID) {
                                // find the match process ID and close its socket
                                position = i;
                                //close the current Socket
                                Server_Game.gameProcessList.get(position).getConnectingSocket().close();

                            } else if (Server_Game.gameProcessList.get(i).getUserName().matches(forwardName)) {
                                //find the formard username and send the refuse message to play partner
                                //instiate the output stream based on other ClientProcess connecting Sockets
                                this.outputStream = new DataOutputStream(Server_Game.gameProcessList.get(i).getConnectingSocket().getOutputStream());

                                String msg1 = "-MSGRefuse;" + this.userName + ";" + "logged out" + "\n";
                                this.outputStream.writeBytes(msg1);//send MSGRefuse flag

                                String msg2 = "-MSGLogout;" + this.userName + ";" + "logged out" + "\n";
                                this.outputStream.writeBytes(msg2);//send MSGLogout flag

                                Server_Game.printMsg(this.userName + " logged out");
                            } else {
                                //broadcast MSGLogout flag of quit playing message to all the clients
                                this.outputStream = new DataOutputStream(Server_Game.gameProcessList.get(i).getConnectingSocket().getOutputStream());
                                String msg = "-MSGLogout;" + this.userName + ";" + "logged out" + "\n";
                                this.outputStream.writeBytes(msg);
                            }
                        }
                    }

                    //release mutex1 for stopping the thread inside Server thread3
                    GameProcess.mutex1.release();
                    //get the removed ClientProcess postion in ProcessList 
                    GameProcess.threadStopPosition = position;

                    Thread.sleep(1000);

                    //wait at mutex2 until signaled by stopping thread has been executed inside Server thread3
                    GameProcess.mutex2.acquire();

                    Server_Game.printMsg("Client Name: " + Server_Game.gameProcessList.get(position).getUserName() + " process removed");//test
                    //remove this ClientProcess from the list
                    Server_Game.gameProcessList.remove(position);

                    if (Server_Game.playNameList.contains(this.userName)) {
                        Server_Game.playNameList.remove(this.userName);
                    }

                } else if (receivingMsg.startsWith("-Play")) {//forward play request message to the targeting client
                    Server_Game.printMsg(receivingMsg);
                    //flag to indicate that message has been sent sucessfully
                    int flag = 0;//1 is sending to specific target

                    String[] token = receivingMsg.split(";");
                    if (token.length > 0) {
                        String senderName = token[1].trim();//get sender username
                        String forwardName = token[2].trim();//get the forward userName

                        if (!this.userName.matches(senderName)) {
                            printMsg("userName: " + this.userName + ", senderName: " + senderName);
                            throw new AssertionError("userName is not same as senderName");
                        }

                        //search for matching targeting UserName
                        for (GameProcess CP : Server_Game.gameProcessList) {
                            //broadcast the messsage of 'this user starting playing game' at first
                            this.outputStream = new DataOutputStream(CP.getConnectingSocket().getOutputStream());
                            String msg1 = "-MSGPlay;" + this.userName + ";" + "started playing game" + "\n";
                            this.outputStream.writeBytes(msg1);

                            if (CP.getUserName().matches(forwardName)) {//found the matched name
                                flag = 1;

                                // forward msg to targeting client
                                // msg format is "-Request;senderName"
                                String msg2 = "-MSGRequest;" + this.userName + ";" + "invited you playing game" + "\n";
                                // send request to tageting player
                                this.outputStream.writeBytes(msg2);
                            }
                        }
                        if (flag == 0) {
                            printMsg("Exception: not found forward name");
                        }
                    }

                    if (Server_Game.playNameList.contains(this.userName)) {
                        Server_Game.playNameList.remove(this.userName);
                    }

                } else if (receivingMsg.startsWith("-Stop")) {//forward play request message to the targeting client
                    Server_Game.printMsg(receivingMsg);
                    int flag = 0;

                    String[] token = receivingMsg.split(";");
                    if (token.length > 0) {
                        String senderName = token[1].trim();//get sender username
                        String forwardName = token[2].trim();//get the forward userName
                        if (!this.userName.matches(senderName)) {
                            printMsg("userName: " + this.userName + ", senderName: " + senderName);
                            throw new AssertionError("userName is not same as senderName");
                        }

                        for (GameProcess GP : Server_Game.gameProcessList) {
                            //broadcast the messsage of 'this user stopped playing game' at first
                            this.outputStream = new DataOutputStream(GP.getConnectingSocket().getOutputStream());
                            String msg1 = "-MSGStop;" + this.userName + ";" + "stopped playing game" + "\n";
                            this.outputStream.writeBytes(msg1);

                            if (GP.getUserName().matches(forwardName)) {//found the matched name
                                flag = 1;

                                // forward msg to targeting client
                                // msg format is "-Request;senderName"
                                String msg2 = "-MSGRefuse;" + this.userName + ";" + "stopped playing game" + "\n";
                                // send request to tageting player
                                this.outputStream.writeBytes(msg2);
                            }
                            if (flag == 0) {
                                printMsg("Exception: not found forward name");
                            }

                        }
                    }
                    if (!Server_Game.playNameList.contains(this.userName)) {
                        Server_Game.playNameList.add(this.userName);
                    }

                } else if (receivingMsg.startsWith("-Accept")) {//forward accept message to the targeting client
                    Server_Game.printMsg(receivingMsg);
                    //flag to indicate that message has been sent sucessfully
                    int flag = 0;//1 is sending to specific target

                    String[] token = receivingMsg.split(";");
                    if (token.length > 0) {
                        String senderName = token[1].trim();//get sender username
                        String forwardName = token[2].trim();//get the forward userName
                        if (!this.userName.matches(senderName)) {
                            printMsg("userName: " + this.userName + ", senderName: " + senderName);
                            throw new AssertionError("userName is not same as senderName");
                        }

                        //search for matching targeting UserName
                        for (GameProcess GP : Server_Game.gameProcessList) {
                            //broadcast the messsage of 'this user starting playing game' at first
                            this.outputStream = new DataOutputStream(GP.getConnectingSocket().getOutputStream());
                            String msg1 = "-MSGPlay;" + this.userName + ";" + "started playing game" + "\n";
                            this.outputStream.writeBytes(msg1);

                            if (GP.getUserName().matches(forwardName)) {//found the matched name
                                flag = 1;

                                // forward msg to targeting client
                                // msg format is "-Request;senderName"
                                String msg2 = "-MSGAccept;" + this.userName + ";" + "accepted playing game" + "\n";
                                // send request to tageting player
                                this.outputStream.writeBytes(msg2);
                            }
                        }
                        if (flag == 0) {
                            printMsg("Exception: not found forward name");
                        }
                    }
                    if (Server_Game.playNameList.contains(this.userName)) {
                        Server_Game.playNameList.remove(this.userName);
                    }

                } else if (receivingMsg.startsWith("-Refuse")) {//forward refuse message to the targeting client
                    Server_Game.printMsg(receivingMsg);
                    int flag = 0;

                    String[] token = receivingMsg.split(";");
                    if (token.length > 0) {
                        String senderName = token[1].trim();//get sender username
                        String forwardName = token[2].trim();//get the forward userName
                        if (!this.userName.matches(senderName)) {
                            printMsg("userName: " + this.userName + ", senderName: " + senderName);
                            throw new AssertionError("userName is not same as senderName");
                        }

                        for (GameProcess GP : Server_Game.gameProcessList) {
                            //only fordward refuse msg to targeting player, no broadcasting
                            if (GP.getUserName().matches(forwardName)) {//found the matched name
                                flag = 1;
                                this.outputStream = new DataOutputStream(GP.getConnectingSocket().getOutputStream());
                                // forward msg to targeting client
                                // msg format is "-Request;senderName"
                                String msg2 = "-MSGRefuse;" + this.userName + ";" + "refused playing game" + "\n";
                                // send request to tageting player
                                this.outputStream.writeBytes(msg2);
                            }
                            if (flag == 0) {
                                printMsg("Exception: not found forward name");
                            }
                        }
                    }

                } else if (receivingMsg.startsWith("-Rock")) {//set game choice and send to game engine to process
                    Server_Game.printMsg("Receiving msg: " + receivingMsg);

                    this.setGameChoice("Rock");//set game choice
                    GameEngine.INSTANCE.getMutex().acquire();
                    //add data to engine
                    GameEngine.INSTANCE.addGameChoiceToList(new GameChoice(this.userName, this.gameChoice));
                    GameEngine.INSTANCE.getMutex().release();

                    this.setGameChoice("null");//reset

                    if (!Server_Game.playNameList.contains(this.userName)) {
                        Server_Game.playNameList.add(this.userName);
                    }
                    printMsg("gameChoiceList size: " + GameEngine.INSTANCE.getGameChoiceList_Size());

                } else if (receivingMsg.startsWith("-Paper")) {
                    Server_Game.printMsg("Receiving msg: " + receivingMsg);

                    this.setGameChoice("Paper");//set game choice

                    GameEngine.INSTANCE.getMutex().acquire();
                    //add data to engine
                    GameEngine.INSTANCE.addGameChoiceToList(new GameChoice(this.userName, this.gameChoice));
                    GameEngine.INSTANCE.getMutex().release();

                    this.setGameChoice("null");//reset

                    if (!Server_Game.playNameList.contains(this.userName)) {
                        Server_Game.playNameList.add(this.userName);
                    }

                    printMsg("gameChoiceList size: " + GameEngine.INSTANCE.getGameChoiceList_Size());

                } else if (receivingMsg.startsWith("-Scissor")) {
                    Server_Game.printMsg("Receiving msg: " + receivingMsg);

                    this.setGameChoice("Scissor");//set game choice

                    GameEngine.INSTANCE.getMutex().acquire();
                    //add data to engine
                    GameEngine.INSTANCE.addGameChoiceToList(new GameChoice(this.userName, this.gameChoice));
                    GameEngine.INSTANCE.getMutex().release();

                    this.setGameChoice("null");//reset

                    if (!Server_Game.playNameList.contains(this.userName)) {
                        Server_Game.playNameList.add(this.userName);
                    }
                    printMsg("gameChoiceList size: " + GameEngine.INSTANCE.getGameChoiceList_Size());

                }

                Thread.sleep(1000);

            }

        } catch (Exception ex1) {
            Server_Game.printMsg(ex1.toString());
        } catch (AssertionError ex2) {
            Server_Game.printMsg(ex2.toString());
        }
    }

    @Override
    public void run() {
        this.clientProcessRun();
    }

    //printer
    private void printMsg(String e) {
        System.out.println(e);
    }

}
