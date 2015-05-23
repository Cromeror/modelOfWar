/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.category.DefaultCategoryDataset;

/**
 *
 * @author Karen
 */
public class Grafic {

    private static final PlotOrientation HORIZONTAL = PlotOrientation.HORIZONTAL;
    private static final PlotOrientation VERTICAL = PlotOrientation.VERTICAL;

    private JFreeChart grafica;
    private DefaultCategoryDataset datos;

    public Grafic() {
        this.datos = new DefaultCategoryDataset();
    }

    /**
     * Genera la grafica con los valores agregados a la instancia
     *
     * @param title String
     * @param labelH String
     * @param labelV String
     * @param orientation: se debe elegir una de las variables static de la
     * clase (Grafica.Horizontal, Grafica.Vertical)
     * @return ChartPanel: Es el tipo de componente que se agregara al
     * contenedor deseado
     */
    public ChartPanel generateGrafica(String title, String labelH, String labelV, PlotOrientation orientation) {
        grafica = ChartFactory.createBarChart(title,
                labelH, labelV, datos, orientation, true, true, false);
        return new ChartPanel(grafica);
    }

    /**
     *Agrega datos para mostrar en la grafica.
     * @param value: el valor que se va a graficar
     * @param group: El identificador del grupo de datos. Si se ha de graficar
     * datos de diferentes tipos, se le coloca diferentes identificadores.
     * @param label : La etiqueta de la columna en el gráfico de barras.
     */
    public void setDatos(int value, String group, String label) {
        datos.addValue(value, group, label);
    }

    public DefaultCategoryDataset getDatos() {
        return datos;
    }

}
