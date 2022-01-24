/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package elec366_lab_04;

/**
 *
 * @author yifan
 */
public class GameChoice {

    String playName = "null";
    String gameChoice = "null";

    public GameChoice(String a, String b) {
        this.playName = a;
        this.gameChoice = b;
    }

    public String getPlayName() {
        return playName;
    }

    public void setPlayName(String playName) {
        this.playName = playName;
    }

    public String getGameChoice() {
        return gameChoice;
    }

    public void setGameChoice(String gameChoice) {
        this.gameChoice = gameChoice;
    }

}
