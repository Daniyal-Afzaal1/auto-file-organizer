//contains the logic to check file types and move files
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




//         #include <iostream>
// #include <filesystem>
// #include <cstdlib>

// namespace fs = std::filesystem;

// int main()
// {
//     char* homeDir = getenv("HOME");

//     if(homeDir == nullptr)
//         homeDir = getenv("USERPROFILE");

//     if(homeDir == nullptr)
//     {
//         std::cout << "Cannot find home directory\n";
//         return 1;
//     }

//     fs::path downloads = fs::path(homeDir) / "Downloads";

//     std::cout << "Downloads folder is: " << downloads << std::endl;

//     if(fs::exists(downloads))
//         std::cout << "Folder exists\n";
//     else
//         std::cout << "Folder NOT found\n";

//     return 0;


