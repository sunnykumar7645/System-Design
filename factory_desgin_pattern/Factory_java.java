
interface Vehicle{
    public void createVehicle();

}

class Car implements Vehicle{
    @Override
    public void createVehicle() {
        System.out.println("Car created");
    }
}

class Bike implements Vehicle{
    @Override
    public void createVehicle() {
        System.out.println("Bike created");
    }
}
class VehicleFactory{
    public static Vehicle createVehicle(String vehicleType){
        if(vehicleType.equalsIgnoreCase("car")){
            return new Car();
        } else if(vehicleType.equalsIgnoreCase("bike")){
            return new Bike();
        }
        return null;
    }
}



public class Factory_java{

    public static void main(String[] args){

        Vehicle car = VehicleFactory.createVehicle("car");
        car.createVehicle();

        Vehicle bike = VehicleFactory.createVehicle("bike");
        bike.createVehicle();

    }
}