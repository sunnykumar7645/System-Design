#include<bits/stdc++.h>

using namespace std;

class HttpRequest{
private:
    string method;
    string url;
    string body; 
    map<string, string> headers;   
    HttpRequest(){}
public:

    friend class HttpRequestBuilder;

 void execute(){
        cout<<"Executing "<<method<<" request to "<<url<<endl;
        cout<<"Headers: "<<endl;
        for(const auto& header: headers){
            cout<<header.first<<": "<<header.second<<endl;
        }
        cout<<"Body: "<<body<<endl;
    }

};

class HttpRequestBuilder{
private:
    HttpRequest request;
public:
    HttpRequestBuilder& setMethod(const string& method){
        request.method = method;
        return *this;
    }
    HttpRequestBuilder& setUrl(const string& url){
        request.url = url;
        return *this;
    }
    HttpRequestBuilder& setBody(const string& body){
        request.body = body;
        return *this;
    }
    HttpRequestBuilder& addHeader(const string& key, const string& value){
        request.headers[key] = value;
        return *this;
    }
    HttpRequest build(){
        if(request.method.empty() || request.url.empty()){
            throw runtime_error("Method and URL are required to build HttpRequest");
        }
        return request;
    }
};



int main(){
    cout<<"Builder Design Pattern Example in C++"<<endl;

    HttpRequest request = HttpRequestBuilder()
                            .setMethod("POST")
                            .setUrl("https://api.example.com/users")
                            .addHeader("Content-Type", "application/json")
                            .setBody("{\"name\": \"John\", \"age\": 30}")
                            .build();

    request.execute();


    return 0;
}