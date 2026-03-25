// package Builder_design_pattern;

class User {

    private String name;
    private int age;
    private String address; 
    private String phoneNumber;

    private User(Builder builder){
        this.name = builder.name;
        this.age = builder.age;
        this.address = builder.address;
        this.phoneNumber = builder.phoneNumber;
    }
    @Override
    public String toString() {
        return "User{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", email='" + address + '\'' +
                ", phoneNumber='" + phoneNumber + '\'' +
                '}';
    }

    public static class Builder{
        private String name;
        private int age;
        private String address; 
        private String phoneNumber;

        public Builder setName(String name){
            this.name = name;
            return this;
        }
        public Builder setAge(int age){
            this.age = age;
            return this;
        }
        public Builder setAddress(String address){
            this.address = address;
            return this;
        }
        public Builder setPhoneNumber(String phoneNumber){
            this.phoneNumber = phoneNumber;
            return this;
        }
        public User build(){
            return new User(this);
        }
    }
    
}


class BuilderDP{

    public static void main(String args[]){
        User user = new User.Builder()
                        .setName("John Doe")
                        .setAge(30)
                        .setAddress("123 Main St")
                        .setPhoneNumber("555-1234")
                        .build();
        System.out.println(user);

        
    }
}