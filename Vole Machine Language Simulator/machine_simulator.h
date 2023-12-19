#include <bits/stdc++.h>
using namespace std;

#ifndef CLION_PROJECTS_MACHINE_SIMULATOR_H
#define CLION_PROJECTS_MACHINE_SIMULATOR_H

const int NUM_REGISTERS = 16;
const int MEMORY_SIZE = 256;

class MachineSimulator {
private:
    string reg_val[NUM_REGISTERS];
    string mem_val[MEMORY_SIZE];
    int program_counter;
    string IR;
public:
    MachineSimulator() {
        program_counter = 0;
        fill_n(reg_val, NUM_REGISTERS, "00");
        fill_n(mem_val, MEMORY_SIZE, "00");
    }
    string binary(int n) ;
    vector<string>instructions;
    bool valid_value (string ins);
    string convert_hex_bin(string hex);
    string convert_bin_hex(string bin);
    string dec_to_hex(int dec);
    int convert_hex_dec(string hex);
    double floating_point_hex_to_decimal_float(string hexadecimal);
    string return_and_transform_binary(string res);
    void floating_point_addition(string ans,string hex1,string hex2);
    // Function to load a value from memory into a register
    void loadFromMemory(string reg, string memAddress); // operand 1
    // Function to load a value into a register
    void loadRegister(string reg, string value); // operand 2
    // function to load from register into memory
    void StoreInMemory (string reg,string memAddress); // operand 3
    // copy the value of register 1 and put it in register 2
    void copy(string reg1,string reg2); // operand 4
    void display_address_zero(string reg);
    void display_reg(string reg);
    void display_mem(string mem);
    void adding_2s(string ans,string reg1,string reg2);
    void display_memory();
    void display_registers();
    void run_program();
};

#endif //CLION_PROJECTS_MACHINE_SIMULATOR_H
