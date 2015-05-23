
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author familia
 */
public class ControlModelWar {

    public static void init() {
        if (Connection.connect("MODELO de guerra")) {
            try {
                Setting.getInstance().setEIT(Connection.getValueVar("EIT"));
                Setting.getInstance().setEST(Connection.getValueVar("EST"));
                Setting.getInstance().setESH(Connection.getValueVar("ESH"));
                Setting.getInstance().setEITVH(Connection.getValueVar("EITVH"));
                Setting.getInstance().setEITVH(Connection.getValueVar("EITVH"));
                Setting.getInstance().setEITVH(Connection.getValueVar("EITVH"));
                Setting.getInstance().setEITVH(Connection.getValueVar("EITVH"));
                Setting.getInstance().setEITVH(Connection.getValueVar("EITVH"));
            } catch (IOException ex) {
                Logger.getLogger(ControlModelWar.class.getName()).log(Level.SEVERE, null, ex);
            }
        }else{
            JOptionPane.showMessageDialog(null, "No se pudo cargar el modelo");
        }
    }
    public static void initListResult(){
        
    }
}
