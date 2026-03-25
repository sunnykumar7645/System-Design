

interface coffee{
    int cost();
    String description();
}
class BasicCoffee implements coffee{

    @Override
    public int cost(){
        return 100;
    } 
    @Override
    public String description(){
        return "Basic Coffee";

    }
}
abstract class CoffeeDecorator implements coffee{
    protected coffee decoratedCoffee;

    public CoffeeDecorator(coffee c){
        this.decoratedCoffee = c;
    }

    @Override
    public int cost(){
        return decoratedCoffee.cost();
    }
    @Override
    public String description(){
        return decoratedCoffee.description();
    }
}
class milkDecorator extends CoffeeDecorator{

    public milkDecorator(coffee c){
        super(c);
    }

    @Override
    public int cost(){
        return decoratedCoffee.cost() + 20;
    }
    @Override
    public String description(){
        return decoratedCoffee.description() + " with Milk";
    }
}
class sugarDecorator extends CoffeeDecorator{

    public sugarDecorator(coffee c){
        super(c);
    }

    @Override
    public int cost(){
        return decoratedCoffee.cost() + 10;
    }
    @Override
    public String description(){
        return decoratedCoffee.description() + " with Sugar";
    }
}

public class DecoratorDP {

    public static void main(String[] args) {
        // Create a basic coffee
        coffee basicCoffee = new BasicCoffee();
        System.out.println(basicCoffee.description() + " costs: " + basicCoffee.cost());    
        
        // Decorate with milk
        basicCoffee = new milkDecorator(basicCoffee);
        System.out.println(basicCoffee.description() + " costs: " + basicCoffee.cost());
        // Decorate with sugar
        basicCoffee = new sugarDecorator(basicCoffee);
        System.out.println(basicCoffee.description() + " costs: " + basicCoffee.cost());
    }
}