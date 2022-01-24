/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package elec366_lab_04;

import java.awt.Color;
import java.awt.Font;
import javax.swing.ComboBoxModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

/**
 *
 * @author yifan
 */
public class GUI_Game {

    /**
     * ** UI components ****
     */
    //server UI
    private JFrame serverFrame = null;
    private JLabel serverLabel = null;

    //client UI
    private JFrame clientFrame = null;
    private JLabel clientNameLabel = null;
    private JLabel playWithLabel = null;
    private JLabel resultLabel = null;//to implement
    private JTextField clientNameField = null;
    private JComboBox playWithCombo = null;//to implement
    private JButton button_logon = null;
    private JButton button_play = null;

    private JButton button_rock = null;
    private JButton button_paper = null;
    private JButton button_scissor = null;

    private JButton button_accept = null;
    private JButton button_refuse = null;

    private JTextArea exceptionTextArea = null;

    /**
     * ** method part ****
     */
    //constructor
    public GUI_Game() {
        this.serverFrame = new JFrame();
        this.serverLabel = new JLabel();

        this.clientFrame = new JFrame();
        this.clientNameLabel = new JLabel();
        this.playWithLabel = new JLabel();
        this.clientNameField = new JTextField();
        this.playWithCombo = new JComboBox(Client_Game.playNameList);
        this.resultLabel = new JLabel();

        this.button_logon = new JButton();
        this.button_play = new JButton();

        this.button_rock = new JButton();
        this.button_paper = new JButton();
        this.button_scissor = new JButton();
        this.button_accept = new JButton();
        this.button_refuse = new JButton();

        this.exceptionTextArea = new JTextArea();
    }

    // set server UI
    public void drawServer() {//to do...
        //set initial Server UI
        this.serverFrame.setTitle("Chatting Server");
        this.serverFrame.setBounds(100, 100, 300, 300);
        this.serverFrame.getContentPane().setLayout(null);
        this.serverFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        this.serverLabel.setText("No Clients Connected");
        this.serverLabel.setBounds(80, 30, 200, 30);
        this.serverLabel.setForeground(Color.red);
        this.serverFrame.getContentPane().add(this.serverLabel);

        this.serverFrame.setVisible(true);

    }

    //toggle server connection status label
    public void toggleConnectionStatus_Server(boolean connected, String connectingMsg) {
        if (connected) {
            this.serverLabel.setText(connectingMsg);
            this.serverLabel.setForeground(Color.BLUE);
        } else {
            this.serverLabel.setText("No Clients Connected");
            this.serverLabel.setForeground(Color.red);//red fond
        }
    }

    //set client UI
    public void drawClient() {
        // set initial Client UI
        this.clientFrame.setTitle("Game Terminal");
        this.clientFrame.setBounds(100, 100, 600, 600);
        this.clientFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.clientFrame.getContentPane().setLayout(null);

        this.clientNameLabel.setText("Client Name");
        this.clientNameLabel.setBounds(20, 40, 100, 30);
        this.clientNameLabel.setFont(new Font("Times", Font.BOLD, 16));
        this.clientNameLabel.setHorizontalAlignment(SwingConstants.LEFT);
        this.clientNameLabel.setVerticalAlignment(SwingConstants.CENTER);
        this.clientFrame.getContentPane().add(this.clientNameLabel);

        this.clientNameField.setBounds(150, 40, 200, 30);
        this.clientNameField.setFont(new Font("Times", Font.BOLD, 14));
        this.clientFrame.getContentPane().add(this.clientNameField);

        this.button_logon.setText("Log in");
        this.button_logon.setBounds(400, 40, 100, 30);
        this.clientFrame.getContentPane().add(this.button_logon);

        //the following components are initially invisible and disabled
        this.playWithLabel.setText("Play With");
        this.playWithLabel.setBounds(20, 80, 100, 30);
        this.playWithLabel.setFont(new Font("Times", Font.BOLD, 16));
        this.playWithLabel.setHorizontalAlignment(SwingConstants.LEFT);
        this.playWithLabel.setVerticalAlignment(SwingConstants.CENTER);
        this.clientFrame.getContentPane().add(this.playWithLabel);
        this.playWithLabel.setVisible(false);//initially disabled and invisible
        this.playWithLabel.setEnabled(false);

        this.playWithCombo.setBounds(150, 80, 200, 30);
        this.playWithCombo.setFont(new Font("Times", Font.BOLD, 14));
        this.clientFrame.getContentPane().add(this.playWithCombo);
        this.playWithCombo.setEnabled(false);//initially disabled and invisible
        this.playWithCombo.setVisible(false);

        this.button_play.setText("Play");
        this.button_play.setBounds(400, 80, 100, 30);
        this.clientFrame.getContentPane().add(this.button_play);
        this.button_play.setEnabled(false);//initially disabled and invisible
        this.button_play.setVisible(false);

        this.button_rock.setText("ROCK");
        this.button_rock.setBounds(150, 120, 100, 50);
        this.clientFrame.getContentPane().add(this.button_rock);
        this.button_rock.setVisible(false);//initially invisible
        this.button_rock.setEnabled(false);

        this.button_paper.setText("PAPER");
        this.button_paper.setBounds(150, 200, 100, 50);
        this.clientFrame.getContentPane().add(this.button_paper);
        this.button_paper.setVisible(false);//initially invisible
        this.button_paper.setEnabled(false);

        this.button_scissor.setText("SCISSOR");
        this.button_scissor.setBounds(150, 280, 100, 50);
        this.clientFrame.getContentPane().add(this.button_scissor);
        this.button_scissor.setVisible(false);//initially invisible
        this.button_scissor.setEnabled(false);

        this.resultLabel.setBounds(20, 360, 200, 30);
        this.resultLabel.setFont(new Font("Times", Font.BOLD, 16));
        this.resultLabel.setHorizontalAlignment(SwingConstants.LEFT);
        this.resultLabel.setVerticalAlignment(SwingConstants.CENTER);
        this.clientFrame.getContentPane().add(this.resultLabel);
        this.resultLabel.setVisible(false);//initially invisible
        this.resultLabel.setEnabled(false);

        this.button_accept.setText("Accept");
        this.button_accept.setBounds(400, 120, 100, 30);
        this.clientFrame.getContentPane().add(this.button_accept);
        this.button_accept.setVisible(false);//initially invisible
        this.button_accept.setEnabled(false);

        this.button_refuse.setText("Refuse");
        this.button_refuse.setBounds(400, 160, 100, 30);
        this.clientFrame.getContentPane().add(this.button_refuse);
        this.button_refuse.setVisible(false);//initially invisible
        this.button_refuse.setEnabled(false);

        this.exceptionTextArea.setBounds(20, 440, 500, 100);
        this.clientFrame.getContentPane().add(this.exceptionTextArea);
        this.exceptionTextArea.setVisible(false);//initially invisible

        this.clientFrame.setVisible(true);
    }

    //toggle log on button
    public void toggleLogonButton_Client(boolean b) {
        this.toggleLogonUI_Client(b);

        if (b) {//true is connected
            this.button_logon.setText("Log out");

        } else {
            this.button_logon.setText("Log in");
            this.togglePlayUI_Client(false);
            this.setAcptRefusVisible(false);
            this.resultLabel.setVisible(false);
        }
    }

    //toggle log on UI on clicking connect button
    public void toggleLogonUI_Client(boolean b) {
        this.playWithLabel.setEnabled(b);
        this.playWithLabel.setVisible(b);
        this.playWithCombo.setEnabled(b);
        this.playWithCombo.setVisible(b);
        this.button_play.setEnabled(b);
        this.button_play.setVisible(b);

        this.clientNameField.setEnabled(!b);

    }

    //true to click play, false to click stop
    public void togglePlayButton_Client(boolean b) {
        //this.togglePlayUI_Client(b);
        //toggel between stop and play           
        if (b) {//true is to click play
            this.button_play.setText("Stop");
            this.resultLabel.setVisible(false);
        } else {
            this.button_play.setText("Play");
        }

    }

    //true to click accept button, false to click refuse button
    public void clickAcptandRefusButton_Client(boolean acpt) {
        this.togglePlayButton_Client(acpt);
        //this.togglePlayUI_Client(acpt);

        if (acpt) {
            this.setAcptRefusVisible(false);
        } else {
            this.setAcptRefusVisible(false);
        }

    }

    //3 rock, paper , scissor button toggling
    public void togglePlayUI_Client(boolean b) {
        this.button_paper.setEnabled(b);
        this.button_paper.setVisible(b);
        this.button_rock.setVisible(b);
        this.button_rock.setEnabled(b);
        this.button_scissor.setEnabled(b);
        this.button_scissor.setVisible(b);
        this.playWithCombo.setEnabled(!b);

    }

    public void setRockPaperScissorEnable(boolean b) {
        this.button_rock.setEnabled(b);
        //this.button_rock.setVisible(b);
        this.button_paper.setEnabled(b);
        //this.button_paper.setVisible(b);
        this.button_scissor.setEnabled(b);
        // this.button_scissor.setVisible(b);

    }

    //set accept and refuse button visible
    public void setAcptRefusVisible(boolean b) {
        this.button_accept.setEnabled(b);
        this.button_accept.setVisible(b);
        this.button_refuse.setEnabled(b);
        this.button_refuse.setVisible(b);
    }

    //getter
    public JButton getButton_connect() {
        return this.button_logon;
    }

    public JButton getButton_play() {
        return this.button_play;
    }

    public JButton getButton_ROCK() {
        return this.button_rock;
    }

    public JButton getButton_PAPER() {
        return this.button_paper;
    }

    public JButton getButton_SCISSOR() {
        return this.button_scissor;
    }

    public JButton getButton_Accept() {
        return this.button_accept;
    }

    public JButton getButton_Refuse() {
        return this.button_refuse;
    }

    public String getConnectionStatus() {
        return this.button_logon.getText().trim();
    }

    public String getPlayStatus() {
        return this.button_play.getText().trim();
    }

    public JFrame getClientFrame() {
        return clientFrame;
    }

    public String getClientName() {
        return this.clientNameField.getText().trim();
    }

    public String getPlayWithName() {
        return this.playWithCombo.getSelectedItem().toString();
    }

    public void setResultMsg(String str) {
        this.resultLabel.setVisible(true);
        this.resultLabel.setEnabled(true);
        this.resultLabel.setText(str);
    }

    public void setExceptionMsg(String str) {
        this.exceptionTextArea.setVisible(true);
        this.exceptionTextArea.append("\n" + str);
    }
}
