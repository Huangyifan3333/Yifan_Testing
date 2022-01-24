/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package elec366_lab_04;

import java.io.DataOutputStream;
import java.util.ArrayList;
import java.util.concurrent.Semaphore;

/**
 *
 * @author yifan
 */
public enum GameEngine implements Runnable {
    INSTANCE();

    //data
    private ArrayList<GameChoice> gameChoiceList = null;

    private Semaphore mutex = null;//to protect accessing gameChoiceList

    GameEngine() {
        gameChoiceList = new ArrayList();
        mutex = new Semaphore(1);//to protect accessing gameChoiceList
    }

    @Override
    public void run() {
        //run to compare the game result
        try {
            while (!Server_Game.serverSocket.isClosed()) {
                this.mutex.acquire();
                Result result = this.gameCombat();
                this.mutex.release();

                //msg to broadcast
                //String msg1 = "MSGStop;" + result.getWin() + "\n";
                //String msg2 = "MSGStop;" + result.getLose() + "\n";
                if (!(result.getWin().matches("null") || result.getLose().matches("null"))) {
                    printMsg("result loser: " + result.getLose() + " ,result winner: " + result.getWin());

                    for (GameProcess GP : Server_Game.gameProcessList) {

                        //send msg to two player clients and broadcase to the rest clients
                        if (GP.getUserName().matches(result.getWin())) {
                            DataOutputStream outputStream = new DataOutputStream(GP.getConnectingSocket().getOutputStream());
                            String msg = "-MSGResult;" + result.getResultMsg() + "\n";
                            outputStream.writeBytes(msg);

                            printMsg("test match winner");
                        } else if (GP.getUserName().matches(result.getLose())) {
                            DataOutputStream outputStream = new DataOutputStream(GP.getConnectingSocket().getOutputStream());
                            String msg = "-MSGResult;" + result.getResultMsg() + "\n";
                            outputStream.writeBytes(msg);

                            printMsg("test match loser");
                        }

                    }
                }
                result.reset();//clear result after sending the msg

            }
        } catch (Exception ex1) {
            printMsg(ex1.toString());
        }
    }

    public Result gameCombat() {
        Result result = new Result();
        if (this.gameChoiceList.size() == 2) {
            printMsg("gameChoiceList size (inside gameCombat): " + this.gameChoiceList.size());
            String ch0 = this.gameChoiceList.get(0).getGameChoice();
            String ch1 = this.gameChoiceList.get(1).getGameChoice();
            if (ch0 == "Rock") {
                switch (ch1) {
                    case "Rock":
                        //just fill in the result name to send back, not real winner or loser 
                        result.setWin(this.gameChoiceList.get(0).getPlayName());
                        result.setLose(this.gameChoiceList.get(1).getPlayName());
                        result.setResultMsg("Two sides drew! ");
                        break;

                    case "Paper":
                        //fill in the result name to send back 
                        result.setLose(this.gameChoiceList.get(0).getPlayName());
                        result.setWin(this.gameChoiceList.get(1).getPlayName());
                        result.setResultMsg(result.getWin() + " Wins! ");
                        break;

                    case "Scissor":
                        //fill in the result name to send back 
                        result.setWin(this.gameChoiceList.get(0).getPlayName());
                        result.setLose(this.gameChoiceList.get(1).getPlayName());
                        result.setResultMsg(result.getWin() + " Wins! ");
                        break;

                }

            } else if (ch0 == "Paper") {
                switch (ch1) {
                    case "Rock":
                        //fill in the result name to send back 
                        result.setWin(this.gameChoiceList.get(0).getPlayName());
                        result.setLose(this.gameChoiceList.get(1).getPlayName());
                        result.setResultMsg(result.getWin() + " Wins! ");
                        break;

                    case "Paper":
                        //just fill in the result name to send back, not real winner or loser 
                        result.setWin(this.gameChoiceList.get(0).getPlayName());
                        result.setLose(this.gameChoiceList.get(1).getPlayName());
                        result.setResultMsg("Two sides drew! ");
                        break;

                    case "Scissor":
                        //fill in the result name to send back 
                        result.setLose(this.gameChoiceList.get(0).getPlayName());
                        result.setWin(this.gameChoiceList.get(1).getPlayName());
                        result.setResultMsg(result.getWin() + " Wins! ");
                        break;

                }

            } else if (ch0 == "Scissor") {
                switch (ch1) {
                    case "Rock":
                        //fill in the result name to send back 
                        result.setLose(this.gameChoiceList.get(0).getPlayName());
                        result.setWin(this.gameChoiceList.get(1).getPlayName());
                        result.setResultMsg(result.getWin() + " Wins! ");
                        break;

                    case "Paper":
                        //fill in the result name to send back 
                        result.setWin(this.gameChoiceList.get(0).getPlayName());
                        result.setLose(this.gameChoiceList.get(1).getPlayName());
                        result.setResultMsg(result.getWin() + " Wins! ");
                        break;

                    case "Scissor":
                        //just fill in the result name to send back, not real winner or loser 
                        result.setWin(this.gameChoiceList.get(0).getPlayName());
                        result.setLose(this.gameChoiceList.get(1).getPlayName());
                        result.setResultMsg("Two sides drew! ");
                        break;

                }

            }
            //reset gameChoiceList
            this.gameChoiceList.clear();

        }

        return result;
    }

    public void addGameChoiceToList(GameChoice gc) {//maximum two elements in gamechoice list
        try {
            if (this.gameChoiceList.size() > 2) {
                throw new Exception("GameChoiceList could not exceed size two!");
            }
            this.gameChoiceList.add(gc);

        } catch (Exception e) {

        }

    }

    public Semaphore getMutex() {
        return mutex;
    }

    public int getGameChoiceList_Size() {
        return this.gameChoiceList.size();
    }

    //printer
    private void printMsg(String e) {
        System.out.println(e);
    }

}
