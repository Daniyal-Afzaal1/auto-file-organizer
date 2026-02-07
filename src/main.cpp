//deals with user input and overall flow
    #include <iostream>
    #include <filesystem>
    using namespace std;
    namespace fs = std::filesystem; //creates an alias

    int main(){
        fs::path Downloads = "/home/btw/Downloads";
        for(const auto& entry : fs::directory_iterator(Downloads)){
           if(entry.is_directory()){ //skips directories
            continue;
           }

           fs::path filePath = entry.path();
           string ext = filePath.extension();

           fs::path destination;

           // Decides folder based on extension
           if(ext == ".pdf"){
            destination = Downloads/"PDFs";
           }
           else if(ext == ".jpg" || ext == ".png"){
            destination = Downloads/"Images";
           }
           else if(ext == ".mp4" || ext == ".mkv"){
            destination = Downloads/"Videos";
           }
           else{
            continue; //ignores other files
           }

           //Create folder if it not exists
           if(!fs::exists(destination)){
            fs::create_directory(destination);
           }

           //new file Location
           fs::path newLocation = destination/filePath.filename();

           //Move file
           if(!fs::exists(newLocation)){
           fs::rename(filePath, newLocation);
        }

           cout<<"Moved "<<filePath.filename()<<endl;
        }
        return 0;
}