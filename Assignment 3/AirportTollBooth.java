// BT18CSE021 - UJJWAL SHARMA
// ASSIGNMENT 3



import java.io.*;
import java.util.*;
import java.text.*;

public class AirportTollBooth implements Tollbooth {
  int no_of_trucks_since_collec;
  float total_of_all_since_collec;
// Implementing all the functions in the interface
  AirportTollBooth(){
    no_of_trucks_since_collec = 0;
    total_of_all_since_collec = 0;
  }
// Simpley calculate accordingly
  public void calculateToll(Truck obj){
    int axels = obj.getAxels();
    float weight = obj.getTotalweight();
    float total = 5*axels +  (weight/1000)*20;
    System.out.print("Truck arrival - axles: ");
    System.out.print(axels);
    System.out.print(", total weight: ");
    System.out.print(weight);
    System.out.print(", Toll due: ");
    System.out.println(total);
    no_of_trucks_since_collec = no_of_trucks_since_collec+1;
    total_of_all_since_collec = total_of_all_since_collec + total;
  }

  public void collect_toll(){
    System.out.println("*** Collecting receipts ***");
    show_data();
    // After showing the data you append it to the file info.txt
    try {
      FileWriter fileWriter = new FileWriter("info.txt", true); //Set true for append mode
      PrintWriter printWriter = new PrintWriter(fileWriter); // for printinig

      DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss"); // Date format
      Date date = new Date();
      String dateappend = dateFormat.format(date); // convert the  date specified by the format to string
      String to_colle = Float.toString(total_of_all_since_collec); // convert others to string
      String to_trucks = Integer.toString(no_of_trucks_since_collec);
      String textToAppend = dateappend + " -->  Total Trucks : " + to_trucks + " , Total Collection : " + to_colle ; // make the string
      printWriter.println(textToAppend);  //New line
      printWriter.close();


    } catch(Exception e) {
      e.printStackTrace();
    }
    // Reset the variables
    no_of_trucks_since_collec = 0;
    total_of_all_since_collec = 0;
  }
 // simply printing
  public void show_data(){
    System.out.print("Totals since last collection - Receipts: ");
    System.out.print(total_of_all_since_collec);
    System.out.print(" Trucks: ");
    System.out.println(no_of_trucks_since_collec);
  }

  public void datewiseCollectiion(Date d1, Date d2){
    try { //open the file
      File file = new File("info.txt");
      BufferedReader br = new BufferedReader(new FileReader(file));
      String st;
      while ((st = br.readLine()) != null) {
        // take out the date in the file
          String dt = st.substring(0,10);
          SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy"); // make a format for the date same as in the file
          Date actdate = sdf.parse(dt); // parse the format and get the date object
          // If date lies in the range inclusiive
          if( (actdate.after(d1) && actdate.before(d2)) || actdate.equals(d1) || actdate.equals(d2) ){
            System.out.println(st);//print the contents
          }

      }

    } catch(Exception e) {
      e.printStackTrace();
    }

  }


}
