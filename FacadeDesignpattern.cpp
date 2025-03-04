#include<iostream>
#include<string>

// The facade pattern is a structural design pattern that provides a simplified interface to a complex subsystem.
// It acts as a "front door" to hide the complexity of interacting with multiple classes or systems,
// making the subsystem easier to use. Think of it like a resturant menu: you don't need to know hoe the kictchen workd - you 
// just order a dish, and the staff handles the rest.

// Facade : A single class that delegates  client requests to appropriate subsystem classes.
// Subsystem Classes : A set of interconnected classes that perform teh actual work.
// Client : Interacts with the facade instead of the subsystem directly.


// Starting a computer involves complex steps(CPU, mEMORY, HARDdRIVE). A ComputerFacade
// Simplifies the process.
class CPU
{
  public:
     void freeze(){ std::cout << "CPU Freeze\n";}
     void jump(long position){ std::cout << "CPU: Jump to " << position << "\n";}
     void execute(){ std::cout << "CPU :Execute "; }
};

class Memory
{
    public:
    void load(long position, const std::string& data){
       std::cout << "Memory load Data" << data << " at " << position << "\n";
    }
};

class HardDrive
{
    public:
    std::string read(long sector, int size)
    {
        return "Boot sector data (sector " + std::to_string(sector) + ")";
    }
};

class ComputerFacade
{
    private:
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
    const long BOOT_ADDRESS = 0x7C00;
    const long BOOT_SECTOR = 1;
    const int SECTOR_SIZE = 512;

    public:
     void start()
     {
        cpu.freeze();
        memory.load(BOOT_ADDRESS, hardDrive.read(BOOT_SECTOR,SECTOR_SIZE));
        cpu.jump(BOOT_ADDRESS);
        cpu.execute();
     }
};

int main()
{
    ComputerFacade computer;
    computer.start();
    return 0;
}