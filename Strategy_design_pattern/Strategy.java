interface Walkable{
    public void walk();
}

interface Flyable{
    public void fly();
}

interface Talkable{
    public void talk();
}

class Walk implements Walkable{
    @Override
    public void walk() {
        System.out.println("Walking...");
    }
}

class NoWalk implements Walkable{
    @Override
    public void walk() {
        System.out.println("Cannot walk...");
    }
}

class Fly implements Flyable{
    @Override
    public void fly() {
        System.out.println("Flying...");
    }
}

class NoFly implements Flyable{
    @Override
    public void fly() {
        System.out.println("Cannot fly...");
    }
}

class Talk implements Talkable{
    @Override
    public void talk() {
        System.out.println("Talking...");
    }
}

class NoTalk implements Talkable{
    @Override
    public void talk() {
        System.out.println("Cannot talk...");
    }
}

class Champion{
    private Walkable walkBehavior;
    private Flyable flyBehavior;
    private Talkable talkBehavior;

    public Champion(Walkable walkBehavior, Flyable flyBehavior, Talkable talkBehavior) {
        this.walkBehavior = walkBehavior;
        this.flyBehavior = flyBehavior;
        this.talkBehavior = talkBehavior;
    }

    public void performWalk(){
        walkBehavior.walk();
    }

    public void performFly(){
        flyBehavior.fly();
    }

    public void performTalk(){
        talkBehavior.talk();
    }
}





class Strategy{
    public static void main(String[] args){

        Champion champion1 = new Champion(new Walk(), new Fly(), new Talk());
        champion1.performWalk();
        champion1.performFly();
        champion1.performTalk();

        Champion champion2 = new Champion(new NoWalk(), new NoFly(), new NoTalk());
        champion2.performWalk();
        champion2.performFly();
        champion2.performTalk();

    }
}