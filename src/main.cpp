//deals with user input and overall flow
    #include <iostream>
    #include <filesystem>
    using namespace std;
    namespace fs = std::filesystem; //creates an alias

    int main(){
      int choice;
      do{
      cout << R"(     _   _   _ _____ ___        n_____ ___ _     _____       ___  ____   ____    _    _   _ ___ __________ ____  
    / \ | | | |_   _/ _ \      |  ___|_ _| |   | ____|     / _ \|  _ \ / ___|  / \  | \ | |_ _|__  / ____|  _ \ 
   / _ \| | | | | || | | |_____| |_   | || |   |  _| _____| | | | |_) | |  _  / _ \ |  \| || |  / /|  _| | |_) |
  / ___ \ |_| | | || |_| |_____|  _|  | || |___| |__|_____| |_| |  _ <| |_| |/ ___ \| |\  || | / /_| |___|  _ < 
 /_/   \_\___/  |_| \___/      |_|   |___|_____|_____|     \___/|_| \_\\____/_/   \_\_| \_|___/____|_____|_| \_\
                                                                                                                )";

    cout<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"          MENU"<<endl;
    cout<<"1. Organize the Files"<<endl;
    cout<<"2. Exit"<<endl; 
    cout<<"Enter your choice: "<<endl;
    cin>>choice;
    cin.ignore();
    if(choice == 1){
      string Spath;
      fs::path Path;
      cout<<"Copy or Enter the Path where you want to oraganize files"<<endl;
      getline(cin,Spath); // in string as path can have space 
      // Path = Spath;
      if(Spath.)
      if(!fs::exists(Path) || !fs::is_directory(Path)){
        cout<<"Path does not exits or is not a folder!"<<endl;
        continue;
      }
      else{
        cout<<"Organizing files in: "<< Path <<endl;
      }
      

    }
    else if(choice == 2){
      cout<<"Quitting...."<<endl;
    }
    else{
      cout<<"- Enter correct number from the menu !"<<endl;
      continue;
    }                                                                                                         
      
      }while(choice!=2);
      
      
    }