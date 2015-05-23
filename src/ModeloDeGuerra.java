

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Cristobal
 */
public class ModeloDeGuerra {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        if (Vensim.command("SPECIAL>LOADMODEL|MODELO de guerra.vmf") == 1) {
            
            
            ViewModelWar mainView = new ViewModelWar();
            mainView.setVisible(true);
//            int puntos = Vensim.get_data("Current1.vdf", "T", "Time", r.getT_Y(), r.getT_X(), 10);
//            System.out.println("ESH" + r.getESH()[0]);
////            For para imprimir los datos de cualquiera de los dos ejes
//            System.out.println("*********************");
//            for (int i = 0; i < puntos; i++) {
//                System.out.println("T_ " + (i + 1) + ": " + r.getT_Y()[i]);
//            }
        } else {
            System.out.println("Error al cargar modelo");
        }
    }
}
