#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> pageTable;

void loadPage(int pageNumber, int frameNumber)
{
    pageTable[pageNumber] = frameNumber;
}

int getPhysicalAddress(int logicalAddress)
{
    int pageSize = 0x100;
    int pageNumber = (logicalAddress >> 8) & 0xFF;  // Extracting page number
    int offset = logicalAddress & 0xFF;            // Extracting offset
    
    if(pageTable.find(pageNumber) == pageTable.end())
    {
        return pageNumber; // Return page number in case of page fault
    }
    else
    {
        int frameNumber = pageTable[pageNumber];
        int physicalAddress = (frameNumber * pageSize) + offset;
        return physicalAddress;
    }
}

void processLogicalAddress(int logicalAddress)
{
    int physicalAddress = getPhysicalAddress(logicalAddress);
    
    if (physicalAddress == -1) {
        cout << "Page fault at Logical Address: 0x" << hex << logicalAddress << "\n";
    } else {
        int pageSize = 0x100;
        int pageNumber = (logicalAddress >> 8) & 0xFF;  // Extracting page number
        int offset = logicalAddress & 0xFF;            // Extracting offset
        cout << "Logical Address: 0x" << hex << logicalAddress 
             << " => Page Number: 0x" << hex << pageNumber 
             << ", Offset: 0x" << hex << offset << "\n";
    }
}

int main()
{
    loadPage(0x0D, 0x03);
    loadPage(0x2B, 0x0A);
    loadPage(0x15, 0x05);
    
    int logicalAddress;
    
    logicalAddress = 0x3A7F;
    processLogicalAddress(logicalAddress);
    
    logicalAddress = 0xABCD;
    processLogicalAddress(logicalAddress);
    
    logicalAddress = 0x5678;
    processLogicalAddress(logicalAddress);
    
    
    return 0;
}
