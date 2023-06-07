#include <iostream>
#include <fstream>
//#include "backend/Initialize.h"
#include "UI/accountSystem.h"
//#include "UI/accountMenu.h"
//#include "backend/collection.h"
#include "backend/crow_all.h"
//#include "backend/parse.h"


using namespace std;

int main() {
    Database curData;


    crow::SimpleApp app; //define your crow application
    //crow::mustache::set_global_base("Frontend");

    CROW_ROUTE(app, "/")([](const crow::request& req, crow::response& res){
        // Serve the HTML file
        std::ifstream file("Frontend/homepage.html");
        if (file.is_open()) {
            std::stringstream buffer;
            buffer << file.rdbuf();
            file.close();

            res.set_header("Content-Type", "text/html");
            res.write(buffer.str());
        } else {
            res.code = 404;
            res.write("File not found");
        }
        res.end();
    });

    /*CROW_ROUTE(app, "/homepage.html")([](const crow::request& req, crow::response& res){
        // Serve the HTML file
        std::ifstream file("Frontend/homepage.html");
        if (file.is_open()) {
            std::stringstream buffer;
            buffer << file.rdbuf();
            file.close();

            res.set_header("Content-Type", "text/html");
            res.write(buffer.str());
        } else {
            res.code = 404;
            res.write("File not found");
        }
        res.end();
    });*/


    CROW_ROUTE(app, "/login_frontend.html")([&curData](const crow::request& req, crow::response& res){
        // Serve the HTML file
        std::ifstream file;
        if(curData.isLoggedIn()){
            file.open("Frontend/profile.html");
        }
        else {
            file.open("Frontend/login_frontend.html");
        }
        if (file.is_open()) {
            std::stringstream buffer;
            buffer << file.rdbuf();
            file.close();

            res.set_header("Content-Type", "text/html");
            res.write(buffer.str());
        } else {
            res.code = 404;
            res.write("File not found");
        }
        res.end();
    });

    CROW_ROUTE(app, "/submit")([&curData](crow::request& req, crow::response& res) {
        // Extract data from the submitted form

//        curData.readFile("assets/records.csv");

        std::string username = req.url_params.get("name");
        std::string password = req.url_params.get("password");

        // Process the extracted data
        // ...

        // Send a response
        registration(curData, username, password);
        res.code = 302;
        res.add_header("Location", "/");
        res.end();
    });
    CROW_ROUTE(app, "/login")([&curData](crow::request& req, crow::response& res) {
        if(!curData.isLoggedIn()){
            //not logged in
            string username = req.url_params.get("username");
            string password = req.url_params.get("password");
            bool result = curData.canLogin(username,password);

            if(result){
                //upon login, redirect to profile
                curData.login(username,password);
                res.code = 302;
                res.add_header("Location", "/profile.html");
            }
            else{
                //cannot login because username/password wrong
                res.code = 302;
                res.add_header("Location", "/login_frontend.html");
                //say can't log in somehow
            }
        }
        else{
            //already logged in, redirects to profile page
            //this shouldn't be accessible unless they type the link in manually
            res.code = 302;
            res.add_header("Location", "/profile.html");
        }
        res.end();
    });

    CROW_ROUTE(app, "/logout")([&curData](crow::request& req, crow::response& res) {
        curData.logout();
        res.code = 302;
        res.add_header("Location", "/homepage.html");
        res.end();
    });

    CROW_ROUTE(app, "/register.html")([](const crow::request& req, crow::response& res){
        std::ifstream file("Frontend/register.html");
        if (file.is_open()) {
            std::stringstream buffer;
            buffer << file.rdbuf();
            file.close();

            res.set_header("Content-Type", "text/html");
            res.write(buffer.str());
        } else {
            res.code = 404;
            res.write("File not found");
        }
        res.end();
    });

    CROW_ROUTE(app, "/forgotpass.html")([](const crow::request& req, crow::response& res){
        std::ifstream file("Frontend/forgotpass.html");
        if (file.is_open()) {
            std::stringstream buffer;
            buffer << file.rdbuf();
            file.close();

            res.set_header("Content-Type", "text/html");
            res.write(buffer.str());
        } else {
            res.code = 404;
            res.write("File not found");
        }
        res.end();
    });


    CROW_ROUTE(app, "/listPage.html/<string>/<int>")([&curData](const crow::request& req, crow::response& res, const std::string file_name, const int pageNumber ){
        //this is the file name of the csv in the url
        std::string csvName = "assets/" + file_name;
        std::stringstream buffer;
        std::ifstream file("Frontend/listPage.html");
        if (file.is_open()) {




            buffer << file.rdbuf();
            file.close();

            res.set_header("Content-Type", "text/html");
//            res.write(buffer.str());
        } else {
            res.code = 404;
            res.write("File not found\n NOOOOOOOOOOOOO");
        }
        //code here
        string colName = csvName.substr(csvName.find("-") + 1);
        string uName = csvName.substr(csvName.find('/') +1, csvName.find("-") - csvName.find('/')-1 );

//        Collection tempCollection(curData.getCollection(colName , uName));

        string temp = buffer.str();
        string placeholder = "CurrentPageNumber";
        size_t pos = temp.find(placeholder);
        if(pos != string::npos){
            temp.replace(pos, placeholder.length(), to_string(pageNumber));
        }
        //loop through colletions vector and write actual html code
        Collection test(curData.getCollection(colName , uName));
        string tableStuff;
        int thingy = curData.getCollection(colName , uName).size();
        for(int i = 0; i < 10; i++){
            bird_record tempBird = curData.getCollection(colName , uName).getBird((pageNumber-1)*10 + i);
            tableStuff += "<tr>";
            tableStuff += "<td>" + tempBird.getCommonName() + "</td>";
            tableStuff += "<td>" + tempBird.getLocality() + "</td>";
            tableStuff += "<td>" + tempBird.getObservationDate() + "</td>";
            tableStuff += "</tr>";
        }

        placeholder = "{{Pageinfo}}";
        pos = temp.find(placeholder);
        if(pos != string::npos){
            temp.replace(pos, placeholder.length(), tableStuff);
        }

        res.write(temp);
        res.end();
    });

    CROW_ROUTE(app, "/listPage.html/<string>/<int>/prevPage")([&curData](const crow::request& req, crow::response& res, const std::string file_name, const int &pageNumber ){
        //this is the file name of the csv in the url
        res.code = 302;
        //res.write(to_string(pageNumber));
        int prevVal;
        if(pageNumber > 1){
            prevVal= pageNumber-1;
        }
        res.add_header("Location", "/listPage.html/" + file_name + "/" + to_string(prevVal));
        res.end();
    });

    CROW_ROUTE(app, "/listPage.html/<string>/<int>/nextPage")([&curData](const crow::request& req, crow::response& res, const std::string file_name, const int &pageNumber ){
        //this is the file name of the csv in the url
        std::string csvName = "assets/" + file_name;
        string colName = csvName.substr(csvName.find("-") + 1);
        string uName = csvName.substr(csvName.find('/') +1, csvName.find("-") - csvName.find('/')-1 );
        res.code = 302;
        int nextVal;
        if(pageNumber < (curData.getCollection(colName , uName).size()/10)){
            nextVal = pageNumber+1;
        }
        res.add_header("Location", "/listPage.html/" + file_name + "/" + to_string(nextVal));
        res.end();
    });

    CROW_ROUTE(app, "/<path>")
            ([](const crow::request& req, crow::response& res, const std::string& path) {
                std::string extension = path.substr(path.find_last_of(".") + 1);
                std::string content_type;

                std::ifstream file(path);
                if (extension == "css") {
                    content_type = "text/css";
                } else if (extension == "js") {
                    content_type = "application/javascript";
                } else if (extension == "png") {
                    content_type = "image/png";
                } else if (extension == "jpg" || extension == "jpeg") {
                    content_type = "image/jpeg";
                } else if (extension == "html") {
                    content_type = "text/html";
                    file.open("Frontend/" + path);
                }

//                cout << path << endl;
                if (file.is_open()) {

                    // Add more conditions for other file types if needed

                    // Set the appropriate response headers
                    res.set_header("Content-Type", content_type);

                    // Read the file contents into a string
                    std::stringstream buffer;
                    buffer << file.rdbuf();
                    file.close();

                    // Send the file contents as the response
                    if(content_type != "text/html") {
                        res.set_static_file_info(path);
                    }
                    else{
                        res.write(buffer.str());
                    }
                } else {
                    res.code = 404;
                    res.write("File not found\n AAAAAAAAAAAAAH");
                }
                res.end();
            });

    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();
    return 0;
};
