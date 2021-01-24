// BT18CSE021 - UJJWAL SHARMA
// ASSIGNMENT 3

import java.util.*;
public interface Tollbooth {
  void show_data(); // to show data
  void collect_toll(); // to collect toll
  void calculateToll(Truck obj); // to calculate toll for specified truck
  void datewiseCollectiion(Date d1, Date d2); // For datewise collectoin
}
