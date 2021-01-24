// BT18CSE021 - UJJWAL SHARMA
// ASSIGNMENT 3 

public class TataTruck implements Truck{
  int axels;
  float weight;
  // Implementing all the functions in the interface
  TataTruck(int axels,float weight){
    setAxels(axels);
    setWeight(weight);
  }
  public void setAxels(int a){
    axels = a;
  }
  public void setWeight(float w){
    weight = w;
  }
  public int getAxels(){
    return axels;
  }
  public float getTotalweight(){
    return weight;
  }
}
