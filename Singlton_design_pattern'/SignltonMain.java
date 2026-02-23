

class SingltonClass{
    // private static SingltonClass instance;
    static SingltonClass instance = null;

    private SingltonClass(){}

    public static SingltonClass getInstance(){
        if(instance == null){
            instance = new SingltonClass();
        }
        return instance;
    }
    public void display(){
        System.out.println("This is a singleton class");
    }
}

public class SignltonMain{

    public static void main(String[] args) {
        SingltonClass obj1 = SingltonClass.getInstance();
        SingltonClass obj2 = SingltonClass.getInstance();

        System.out.println(obj1);
        System.out.println(obj2);

        if(obj1 == obj2){
            System.out.println("Both objects are the same instance");
        } else {
            System.out.println("Both objects are different instances");
        }
    }
}