/**
   Toothpicks. 
   @author Max Jardine
   @date 12/09/2017
   A java 8 program which draws a field of straight lines that 
   are perpendicular to each other. The lines are placed relative to their 
   predecessor and the amount of lines is determined by the first argument 
   supplied by the user (MUST BE INT). The length of the lines can be made to 
   diminish as the number of lines increases by adding a float argument after 
   the int argument. If this float argument is greater than 1 then the inverted 
   value of that argument will be used to diminish the line length.
*/
import javax.swing.*;
import java.awt.*;
public class Toothpicks extends JFrame{
    /*I have used static variables to represent the consistent values 
      required by a recursive method, as they put an upper bound on the 
      iterelns of the recursive method and stop it from getting trapped in 
      an infinite loop. The SIZE variable is set at 500 to keep the output 
      display within the bounds of a small laptop's screen. This can be easily 
      adjusted for larger screens. The float rel is the relative size of
      the toothpicks being added. The integer n is the number of generelns of
      toothpicks being drawn up. The float scale is the scale at which their 
      size diminishes, this is one of the values pulled off the command line 
      however it's existence is conditional (unlike the necessary n).*/
    public static final int SIZE = 500;
    public static float rel;
    public static int n;
    public static float scale;
    /*main method takes the two command line arguments for number of
      generations and scale, or just one argument for number of generations.*/
    public static void main(String[] args){
        /*The try/catch opereln in my main loop takes care of the variable
          number of command line arguments.*/
        if (args.length == 2) {
            try {
                scale = Float.parseFloat(args[1]);
                n = Integer.parseInt(args[0]);
		if(scale > 1){
		    scale = 1/scale;
		}
                if(n > 3){
                    rel = (((float)(SIZE-(SIZE/5))/(float)n))/scale;
                } else {
                    rel = SIZE/5;
                }
            } catch (NumberFormatException e) {
                System.err.println("Argument" + args[0] +
                                   " must be an integer.");
                System.exit(1);
            }
        } else if(args.length ==1){
            try{
                n = Integer.parseInt(args[0]);
                scale = (float)1.0;
                if(n > 3){
                    rel = ((float)(SIZE-(SIZE/4))/(float)n);
                } else {
                    rel = SIZE/4;
                }
            }catch (NumberFormatException e) {
                System.err.println("Argument" + args[0] +
                                   " must be an integer.");
                System.exit(1);
            }
        }        
        Toothpicks frame = new Toothpicks();
        frame.setSize(SIZE, SIZE);
        frame.setVisible(true);
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    /**This method here does the recursive heavy lifting. It makes calls to
       the graphics module being implimented to draw the toothpicks. It also
       takes the number of generations as a parameter(maxD), the current
       generation being drawn (d)(initially zero of course), the x and y
       coordinate of the centre point of the most recently drawn toothpick, and
       the scale at which the toothpicks reduce in size between generations.
       @param d, int, Current genereln of toothpick being drawn.
       @param maxD, int, Number of generelns to be drawn.
       @param page, Graphics object, Graphics object which is displaying the 
       toothpicks.
       @param x, int, The x coordinate of the centre of the toothpick.
       @param y, int, The y coordinate of the centre of the toothpick.
       @param i, float, Scaling proportion of toothpick length.*/
    public void recursiveToothpick(int d, int maxD, Graphics page, int x,
                                int y, float i){
        while(d <= maxD){ //This checks whether the limit has been reached.
            /*The first line draws a horizontal line then increments the
              count.*/
            page.drawLine(x-Math.round(i*scale), y, x+Math.round(i*scale), y);
            d++;
            if(d <= maxD){ //This also checks whether the limit has bee reached.
                /*The first iteration requires slight different scaling to
                  allow for the fact that the first line is not scaled down and
                  so that the recalculation of linesize in each recursive layer
                  is only one opereln.*/
                if(d == 1){
                    page.drawLine(x-Math.round(i), y-Math.round(i*scale),
                                  x-Math.round(i), y+Math.round(i*scale));
                    page.drawLine(x+Math.round(i), y-Math.round(i*scale),
                                  x+Math.round(i), y+Math.round(i*scale));
                    d++;
                    recursiveToothpick(d, maxD, page, x-Math.round(i),
                                    y-Math.round(i*scale), i*scale);
                    recursiveToothpick(d, maxD, page, x-Math.round(i),
                                    y+Math.round(i*scale), i*scale);
                    recursiveToothpick(d, maxD, page, x+Math.round(i),
                                    y-Math.round(i*scale), i*scale);
                    recursiveToothpick(d, maxD, page, x+Math.round(i),
                                    y+Math.round(i*scale), i*scale);
                    /*Otherwise the vertical toothpicks are drawn two at a time
                      and are scaled appropriately. The method is recursively
                      called 4 times, one for each endpoint of the vertical
                      toothpicks.*/
                } else {
                    page.drawLine(x-Math.round(i*scale), y-Math.round(i*scale),
                                  x-Math.round(i*scale), y+Math.round(i*scale));
                    page.drawLine(x+Math.round(i*scale), y-Math.round(i*scale),
                                  x+Math.round(i*scale), y+Math.round(i*scale));
                    d++;
                    recursiveToothpick(d, maxD, page, x-Math.round(i*scale),
                                    y-Math.round(i*scale), i*scale);
                    recursiveToothpick(d, maxD, page, x-Math.round(i*scale),
                                    y+Math.round(i*scale), i*scale);
                    recursiveToothpick(d, maxD, page, x+Math.round(i*scale),
                                    y-Math.round(i*scale), i*scale);
                    recursiveToothpick(d, maxD, page, x+Math.round(i*scale),
                                    y+Math.round(i*scale), i*scale);
                }
            }
            return;
        }
        return;
    }
                
    /**This paint method draws the page up and the initialises the recursive
       method to draw up all the toothpicks.*/
    public void paint (Graphics page){
        page.setColor(Color.white);
        page.fillRect(0, 0, SIZE, SIZE);
        setTitle("Toothpicks");

        page.setColor(Color.black);
        page.drawLine((SIZE/2)-Math.round(rel), SIZE/2,
                      (SIZE/2)+Math.round(rel), SIZE/2);
        recursiveToothpick(0, n, page, SIZE/2, SIZE/2, rel);
    }
}
