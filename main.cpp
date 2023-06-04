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


    CROW_ROUTE(app, "/listPage.js")
            ([](const crow::request& req, crow::response& res) {
                std::string path= "Frontend/listPage.js";
                std::ifstream file(path);
                if (file.is_open()) {
                    // Determine the content type based on the file extension
                    std::string extension = path.substr(path.find_last_of(".") + 1);
                    std::string content_type;

                    if (extension == "css") {
                        content_type = "text/css";
                    } else if (extension == "js") {
                        content_type = "text/javascript";
                    } else if (extension == "png") {
                        content_type = "image/png";
                    } else if (extension == "jpg" || extension == "jpeg") {
                        content_type = "image/jpeg";
                    }
                    // Add more conditions for other file types if needed

                    // Set the appropriate response headers
                    res.set_header("Content-Type", content_type);

                    // Read the file contents into a string
                    std::stringstream buffer;
                    buffer << file.rdbuf();
                    file.close();

                    // Send the file contents as the response
                    res.write(buffer.str());
                } else {
                    res.code = 404;
                    res.write("File not found");
                }
                res.end();
            });
    CROW_ROUTE(app, "/listPage.css")
            ([](const crow::request& req, crow::response& res) {
                std::string path= "Frontend/listPage.css";
                std::ifstream file(path);
                if (file.is_open()) {
                    // Determine the content type based on the file extension
                    std::string extension = path.substr(path.find_last_of(".") + 1);
                    std::string content_type;

                    if (extension == "css") {
                        content_type = "text/css";
                    } else if (extension == "js") {
                        content_type = "text/javascript";
                    } else if (extension == "png") {
                        content_type = "image/png";
                    } else if (extension == "jpg" || extension == "jpeg") {
                        content_type = "image/jpeg";
                    }
                    // Add more conditions for other file types if needed

                    // Set the appropriate response headers
                    res.set_header("Content-Type", content_type);

                    // Read the file contents into a string
                    std::stringstream buffer;
                    buffer << file.rdbuf();
                    file.close();

                    // Send the file contents as the response
                    res.write(buffer.str());
                } else {
                    res.code = 404;
                    res.write("File not found");
                }
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
                    res.write("File not found");
                }
                res.end();
            });



    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();
    return 0;
};
