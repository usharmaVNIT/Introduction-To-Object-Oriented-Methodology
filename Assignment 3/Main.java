// BT18CSE021 - UJJWAL SHARMA
// ASSIGNMENT 3

public class Main {
  public static void main(String[] args) {
    Tollbooth booth = new AirportTollBooth();
    Truck Tata = new TataTruck(5, 12500); // 5 axles and 12000 kilograms
    booth.calculateToll(Tata);
    Truck Ashok = new AshokTruck(10,50000);
    booth.calculateToll(Ashok);
    booth.collect_toll();
    Truck Tata2 = new TataTruck(6, 14000); // 5 axles and 12000 kilograms
    Truck Tata3 = new TataTruck(7, 20000); // 5 axles and 12000 kilograms
    Truck Ashok2 = new AshokTruck(15,70000);
    Truck Ashok3 = new AshokTruck(20,80000);
    booth.calculateToll(Tata2);
    booth.calculateToll(Tata3);
    booth.calculateToll(Ashok2);
    booth.calculateToll(Ashok3);
    booth.collect_toll();


  }
}
