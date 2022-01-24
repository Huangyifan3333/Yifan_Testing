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
public class Result {
    private String resultMsg ;
    private String win;
    private String lose;
    
    public Result(){
        this.resultMsg="null";
        this.win="null";
        this.lose="null";
    }

    public String getResultMsg() {
        return resultMsg;
    }

    public void setResultMsg(String resultMsg) {
        this.resultMsg = resultMsg;
    }

    public String getWin() {
        return win;
    }

    public void setWin(String win) {
        this.win = win;
    }

    public String getLose() {
        return lose;
    }

    public void setLose(String lose) {
        this.lose = lose;
    }
    
    public void reset(){
        this.setLose("null");
        this.setWin("null");
        this.setResultMsg("null");
    }
}
