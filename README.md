# HW-3-Operating-systems
# A simple program translating logical addresses to physical addresses using a page/frame table.
This project implements a page table in which it stores mappings from logical page numbers to physical frame numbers. Also uses functions to translate logical addresses to physical addresses.
# User instructions/Functionality comprehension
Lets see how this code functions!
* The unordered_map<int, int> named pageTable acts as the page table
  Stores mappings from logical page numbers to physical frame numbers.

* The loadPage function is used to load page-frame mappings into the page table. It takes a page number and a frame number as arguments and inserts them into the pageTable
* The getPhysicalAddress function
  Calculates the physical address corresponding to a given logical address
  Extracts the page number and offset from the logical address
  Checks if the page number exists in the page table. If it does, it calculates the physical address using the frame number from the page table and the offset
  If the page number is not found in the page table, it returns the page number itself, indicating a page fault.
  
* The processLogicalAddress function
  Takes a logical address as input, calls the getPhysicalAddress function to obtain the corresponding physical address
  Prints the details of the logical address, including the page number and offset
  If the getPhysicalAddress function returns a page number, indicating a page fault, it prints a page fault message instead.

  
*  In the main function, we load three page-frame mappings into the page table using the loadPage function
* Then, we process three logical addresses (0x3A7F, 0xABCD, and 0x5678) using the processLogicalAddress function. Finally, the program terminates.

* Lastly this code demonstrates the basic concepts of page-based memory management and illustrates how page faults are handled in such systems.



## User Warnings.
*  In the getPhysicalAddress function, there might be an integer overflow issue when calculating the physical address using (frameNumber * pageSize) + offset. This could happen if the frame number is large, or if the page size is large enough to cause overflow. Ensure that appropriate checks are in place to handle such scenarios.
*  The program correctly handles page faults by loading pages from secondary storage into memory when necessary.
*  Program robustly handles potential errors, such as invalid input addresses or insufficient memory, providing appropriate error messages or gracefully handling such cases.
* One last thing if there are any questions about the functionality of the code, the code itself has a thorough and in-depth explanation from the comments I have put on there.
