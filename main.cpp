#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <time.h>

using namespace std;

void concatenate_string(string&, string);

void videos_download(int);

void pause_console();

bool file_check(string);

void first_convertion();

void rearrange_links();

int count_file_lines();

int main(){
    string file_name="page.html";
    cout << "Please put a page.html file in the current directory: " << endl;
    system("echo | pwd");
    pause_console();
    if(!file_check("page.html")){
        return -1;
    }
    first_convertion();
    rearrange_links();
    count_file_lines();
    videos_download(count_file_lines());
    return 0;
}

void concatenate_string(string &str1, string str2){
    str1+=str2;                                        //Merge the two string into str1
    return;
}


//Passing the video link to yt-dlp to download
void videos_download(int raws){
    string aux, aux1;
    fstream links;
    links.open("links_file.txt");
    for(int i=0;i<raws;i++){
        aux="yt-dlp ";
        aux1.clear();
        links>>aux1;                                    //Save current line link to aux1 string.
        concatenate_string(aux,aux1);
        concatenate_string(aux," -o ");
        concatenate_string(aux,to_string((raws-i)));    //Create the yt-dlp command
        concatenate_string(aux,".mp4");
        system(aux.c_str());                            //Passing the command to yt-dlp
    }
    return;
}

//Equivalent to system("PAUSE") for linux.
void pause_console(){
    char aux;
    do{
        cout << "Press the enter key to continue... ";
    } while(cin.get()!='\n');
    return;
}


//Count file lines and return the exact number of them
int count_file_lines(){
    ifstream inFile("links_file.txt"); 
    return count(istreambuf_iterator<char>(inFile),istreambuf_iterator<char>(), '\n')-1;
}

//Use the first converted file to separate the video links from the rest of the context and put them in another file.
void rearrange_links(){
    system("grep -Po '^.*/video/[0-9]*$' first_convertion_file > links_file.txt");
    return;
}

void first_convertion(){
    system("grep -Po '(?<=href=\")[^\"]*' page.html > first_convertion_file");
    return;
}


//Check if a file exist
bool file_check(string file_name){
    ifstream file(file_name);
    if(!file.is_open()){
        cout << "File not found" << endl;
        return false;                                 //File not found, return false.
    }
    return true;                                      //File found, return true.
}