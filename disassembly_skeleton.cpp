#include <iostream>     // for use of cin, cout, endl
#include <string>       // for use of strings, string member functions
#include <cmath>        // for use of pow(x,y) function
// NO OTHER LIBRARIES ARE ALLOWED!

using namespace std;

// function: disassemble takes in a string representing
//          an assembled MIPS instruction as a string
//          and returns the instruction itself
//
//          This is a limited disassembler: we can safely assume the input is:
//          a) legitimate (an actual MIPS instruction)
//          b) is ONLY an I-type and ONLY one of: addi, addiu, andi, ori, slti, sltiu
//          c) has ONLY registers $t0 thru $t7, or $s0 thru $s7 in the instruction
//


string disassemble(string hex) {

    string result = "";
    string registers[] = {"$t0" ,"$t1", "$t2","$t3","$t4", "$t5", "$t6", "$t7", 
                        "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7"};
    long input = stol(hex, nullptr, 16);

    //opcode: first 6 bits
    //rs: next 5 bits
    //rt: next 5 bits
    //immediate: last 16 bits



    long opcode_mask = 0x0000003F;
    long reg_mask = 0x0000001F;
    long immediate_mask = 0x0000FFFF;

    long immediate = (input & immediate_mask);
    input = input >> 16;
    long rs = (input & reg_mask);
    input = input >> 5;
    long rt = (input & reg_mask);
    input = input >> 5;

    long opcode = (input & opcode_mask);

    //getting command
    if (opcode == 8){
        result += "addi, ";
    }
    else if(opcode == 9){
        result += "addiu, ";
    }
    else if (opcode == 10){
        result += "slti, ";
    }
    else if (opcode == 11){
        result += "sltiu, ";

    }
    else if (opcode == 12){
        result += "andi, ";
    }
    else{
        result += "ori, ";
    }
    
    result += registers[rt - 8] + ", ";
    result += registers[rs - 8] + ", ";

    result += to_string(immediate);
    // You want to retrieve all the separate fields of an I-type instruction
    //      to help you figure out what the assembly instruction is.
    //
    // HINT: Use bitwise masking and bit-shifting to isolate the 
    //      different parts of the hex instruction!
    
    // YOUR CODE GOES HERE!!
 

    /*STEPS:
    1. convert hex to binary
    2. split up the binary into the appropriate sections
    3. convert those sections to  decimal or hex and match to correct value
    4. piece together the instruction*/
    return result;  // remove stub and replace it with correct variable
}

int main() {
// Do NOT change ANY code in main() function!!
//      or you will fail this task (get a zero)

    string hex, inst;
    
    cout << "Enter your assembled instruction as a hex number: 0x";
    cin >> hex;
    
    inst = disassemble( hex );
    cout << "Your instruction is:\n" << inst << endl;

    return 0;
}
