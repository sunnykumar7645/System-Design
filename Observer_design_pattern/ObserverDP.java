
import java.util.ArrayList;
import java.util.List;

interface Observer {
    void update(String msg);
}
interface Subject{
    void addObserver(Observer o);
    void removeObserver(Observer o);
    void notifyObservers(String msg);
}

// you can create concrete classes that implement these interfaces to demonstrate the Observer design pattern. Here's an example implementation:

class Youtube implements Subject{
    private List<Observer> obs = new ArrayList<Observer>();
    private String msg;

    @Override
    public void addObserver(Observer o) {
        obs.add(o); 
    }
    
    @Override
    public void removeObserver(Observer o){
        obs.remove(o);
    }

    @Override
    public void notifyObservers(String msg) {
        for (Observer o : obs) {
            o.update(msg);
        }
    }
    
    public void uploadVideo(String videoTitle) {
        this.msg = "New video uploaded: " + videoTitle;
        notifyObservers(msg);
    }   
}

class Subscriber implements Observer {
    private String name;

    public Subscriber(String name) {
        this.name = name;
    }

    @Override
    public void update(String msg) {
        System.out.println(name + " received notification: " + msg);
    }
}

public class ObserverDP {

    public static void main(String[] args) {
        Youtube youtube = new Youtube();
        
        Subscriber sub1 = new Subscriber("Alice");
        Subscriber sub2 = new Subscriber("Bob");
        
        youtube.addObserver(sub1);
        youtube.addObserver(sub2);
        
        youtube.uploadVideo("Observer Design Pattern Tutorial");
        
        youtube.removeObserver(sub1);
        
        youtube.uploadVideo("Another Video on Design Patterns");
        
    }
}