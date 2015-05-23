/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Karen
 */
public class Connection {

    /**
     * Conecta java con un modelo de Vensim<br>
     * <b>Nota:</b> Solo hay que indicarle el nombre sin la extension del
     * archivo y el modelo tiene que ser de tipo vmf.
     *
     * @param modelName
     * @return
     */
    public static boolean connect(String modelName) {
        /**
         * Array que guardará la información del directorio.
         */
        String array[] = Vensim.get_info(Vensim.INFO_DIRECTORY);
        /**
         * Información de la versión ejecutada.
         */
        System.out.println("Versión de venjava.dll: " + Vensim.get_jversion());
        /**
         * Información del directorio raíz de ejecución.
         */
        System.out.println("Directorio de ejecución de venjava.dll: " + array[0]);
        /**
         * verifica que si esta el modelo guardado en la carpeta raiz del
         * proyecto
         */
        return Vensim.command("SPECIAL>LOADMODEL|" + modelName + ".vmf") == 1;
    }

    /**
     * Hace una corrida del modelo cargado con anterioridad.
     *
     * @param runName
     * @return
     */
    public static boolean run(String runName) {
        int step1 = Vensim.command("SPECIAL>CLEARRUNS");
        int step2 = Vensim.command("SIMULATE>RUNNAME|" + runName);
        int step3 = Vensim.command("MENU>RUN|o");//command make run
        return step1 == 1 && step2 == 1 && step3 == 1;
    }

    /**
     * este metodo modifica los valores de las variables del modelo cargado,
     * deberia usarse antes de hacer una corrida.<br>
     * <b>ver tambien:</b> public static boolean run(String runName)
     *
     * @param varName
     * @param value
     * @return
     */
    public static boolean setValue(String varName, String value) {
        return Vensim.command("SIMULATE>SETVAL|" + varName + "=" + value) == 1;
    }

    /**
     * Retorna el valor de una variable auxiliar
     *
     * @param varName: nombre de la variable
     * @return
     */
    public static float getValueVar(String varName) {
        //Esta funcion solo obtiene un valor
        //Primer parametro: nombre de la variable
        //segundo parametro: array en donde se guardara el valor
        float result[] = new float[1];
        Vensim.get_val(varName, result);
        return result[0];
    }
}
