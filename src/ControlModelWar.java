
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
        }else{
            JOptionPane.showMessageDialog(null, "No se pudo cargar el modelo");
        }
    }
    public static void initListResult(){
        
    }
}
