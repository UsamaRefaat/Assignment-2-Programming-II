// ---------------------------------------------------------------------------------------		 
// File:       machine_simulator.cpp     						 		                             
//                                                                                       
// Purpose:   practice on implementation of large clean code and operator overloading.   
//                                                                                       
// Authors:    Osama Refaat Sayed         20221015 					                     
//             Mostafa Mohamed Anwar      20221153 				                       	 
//             Ziad Tawfik Abdelnabi      20221066  					                 
//                                                                                       
// Section:   S21                                                  		               	 
//                                            			             
// TA:        Rana Abdelkader                                  				             
// Date:      15 NOV 2023     								                             
//                                                                                       
//----------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
#include "machine_simulator.h"

// Explanation:
// The code defines a MachineSimulator class containing various methods to simulate
// operations performed in a hypothetical machine. These methods handle conversions
// between binary, hexadecimal, and decimal representations, perform arithmetic
// operations, manipulate memory, and display the status of registers and memory.

// To execute the simulator, you would typically instantiate the MachineSimulator class
// and call the 'run_program' method, providing a set of instructions to simulate the machine's
// behavior based on the operations specified in the instructions.


string MachineSimulator :: binary(int n) {
    string bin_str="";
    for (int i = 3; i >= 0; --i) {
        int k = n >> i;
        if (k&1) {
            bin_str += '1';
        } else {
            bin_str += '0';
        }
    }
    return bin_str;
} // - 'binary' converts a decimal number to a 4-bit binary string.
bool MachineSimulator ::valid_value(string ins) {
    for(char c: ins) {
        if (c >= '0' && c <= '9') {
            continue;
        } else if (c >= 'A' && c <= 'F') {
            continue;
        } else {return false;}
    }
    return true;
} // - 'valid_value' checks if the instruction contains valid hexadecimal values.
string MachineSimulator ::convert_hex_bin(string hex) {
    string bin = "";
    for (int i = 0; i < hex.size(); ++i) {
        if (hex[i] >= 'A' && hex[i] <= 'F') {
            bin = bin + binary(hex[i] - 'A' +10);
        } else {
            bin = bin + binary(hex[i] - '0');
        }
    }
    if (bin.length() == 4) {
        for (int i = 0 ; i < 4;i++) {
            bin = '0' + bin;
        }
    }
    return bin;
} // - 'convert_hex_bin' converts a hexadecimal string to a binary string.
string MachineSimulator ::convert_bin_hex(string bin) {
    string hex = "";
    int sum1=0,sum2=0;
    for (int i = 0,j = 3; i < 4; ++i,j--) {
        if (bin[i] == '1') {
            sum1 += pow(2,j);
        }
    }
    for (int i = 4,j = 3; i < bin.size(); ++i,j--) {
        if (bin[i] == '1') {
            sum2 += pow(2,j);
        }
    }
    if (sum1 > 9) {
        char hex1 = (sum1 + 'A' - 10);
        hex = hex + hex1;
    } else {
        char hex1 = (sum1 + '0');
        hex = hex + hex1;
    }
    if (sum2 > 9) {
        char hex2 = (sum2 + 'A' - 10);
        hex = hex + hex2;
    } else {
        char hex2 = (sum2 + '0');
        hex = hex + hex2;
    }
    return hex;
} // - 'convert_bin_hex' converts a binary string to a hexadecimal string.
string MachineSimulator ::dec_to_hex(int dec) {
    stringstream stream;
    stream<<hex<<uppercase<<dec;
    return stream.str();
} // - 'dec_to_hex' converts a decimal number to a hexadecimal string.
int MachineSimulator ::convert_hex_dec(string hex) {
    string bin = convert_hex_bin(hex);
    int sum = 0;
    for (int i = 0,j=7; i < bin.size(); ++i,j--) {
        if(bin[i] == '1') {
            sum += pow(2,j);
        }
    }
    return sum;
} // - 'convert_hex_dec' converts a hexadecimal string to a decimal number.
double MachineSimulator ::floating_point_hex_to_decimal_float(string hexadecimal) {
    int size = hexadecimal.size();
    int base = 1;
    int decimal = 0;

    for (int i = size - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (int(hexadecimal[i]) - 48) * base;
            base = base * 16;
        }
        else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (int(hexadecimal[i]) - 55) * base;
            base = base * 16;
        }
    }

    string binary_representation = bitset<8>(decimal).to_string();
    char sign = binary_representation[0];
    string exponent = binary_representation.substr(1, 3);
    string mantissa = binary_representation.substr(4, 7);

    int decimal_exponent = bitset<8>(exponent).to_ulong();
    int shift_amount = decimal_exponent - 4;

    mantissa.insert(shift_amount, ".");

    double decimal_mantissa = 0;

    int pos = mantissa.find('.');
    for (int i = 0; i < mantissa.size(); ++i) {
        if (mantissa[i] == '1') {
            if (i < pos)
                decimal_mantissa += pow(2, pos - 1 - i);
            else
                decimal_mantissa += pow(2, pos - i);
        }
    }

    if (sign == '0')
        return decimal_mantissa;
    else
        return -decimal_mantissa;
} // - 'floating_point_hex_to_decimal_float' converts a hexadecimal floating-point representation to a decimal floating-point number.
string MachineSimulator ::return_and_transform_binary(string res) {
    string binary = "";
    string final;
    bool neg = false;
    if (res[0]=='-')
    {
        neg = true ;
        res.erase(0,1);
    }
    int pos = res.find('.');

    int intPart = stoi(res.substr(0, pos));
    bitset<8> intBinary(intPart);
    string intBinaryStr = intBinary.to_string();

    double fractionPart = stod("0." + res.substr(pos + 1));
    string fractionBinaryStr = "";

    for (int i = 0; i < 8; ++i) {
        fractionPart *= 2;
        int bit = static_cast<int>(fractionPart);
        fractionBinaryStr += to_string(bit);
        fractionPart -= bit;
    }
    final = intBinaryStr + "." + fractionBinaryStr;

    // Remove leading zeros
    int i = 0;
    while (i < final.size() && final[i] == '0') {
        ++i;
    }
    if (i < final.size()) {
        final = final.substr(i);
    } else {
        final = "0";
    }
    int dotPos = final.find('.');
    if (dotPos != string::npos) {
        final.erase(dotPos, 1);
        string mantissa = final.substr(0, 4);
        int exponent = dotPos + 4;
        bitset<3> exponentBinary(exponent);
        final = exponentBinary.to_string() + mantissa;
    }
    if (neg)
        return '1'+final;
    else
        return '0'+final;
} // - 'return_and_transform_binary' transforms a given string into a binary representation.
// - Other functions handle memory operations, arithmetic operations, and display tasks.
void MachineSimulator ::floating_point_addition(string ans, string hex1, string hex2) {
    double decimal_sum =  (floating_point_hex_to_decimal_float(hex1)+floating_point_hex_to_decimal_float(hex2));
    string sum = to_string(decimal_sum);
    reg_val[convert_hex_dec(ans)] = convert_bin_hex(return_and_transform_binary(sum));
}
void MachineSimulator ::loadFromMemory(string reg, string memAddress) {
    reg_val[convert_hex_dec(reg)] = mem_val[convert_hex_dec(memAddress)];
}
void MachineSimulator ::loadRegister(string reg, string value) {
    reg_val[convert_hex_dec(reg)] = value;
}
void MachineSimulator ::StoreInMemory(string reg, string memAddress) {
    mem_val[convert_hex_dec(memAddress)] = reg_val[convert_hex_dec(reg)];
}
void MachineSimulator ::copy(string reg1, string reg2) {
    reg_val[convert_hex_dec(reg2)] = reg_val[convert_hex_dec(reg1)];
}
void MachineSimulator ::display_address_zero(string reg) {
    mem_val[0] = reg_val[convert_hex_dec(reg)];
    cout<<mem_val[0]<<endl;
}
void MachineSimulator ::display_reg(string reg) {
    cout<<reg_val[convert_hex_dec(reg)];
}
void MachineSimulator ::display_mem(string mem) {
    cout<<mem_val[convert_hex_dec(mem)];
}
void MachineSimulator ::adding_2s(string ans, string reg1, string reg2) {
    string num1 = convert_hex_bin(reg_val[convert_hex_dec(reg1)]);
    string num2 = convert_hex_bin(reg_val[convert_hex_dec(reg2)]);
    string sum="";
    char car = '0';
    for (int i = 7; i >= 0; --i) {
        if (num1[i] == '0' && num2[i] == '0') {
            if (car == '1') {
                sum = '1' + sum;
                car = '0';
            } else
                sum = '0' + sum;
        } else if (num1[i] == '1' && num2[i] == '0') {
            if (car == '1') {
                sum = '0' + sum;
                car = '1';
            } else
                sum = '1' + sum;
        } else if (num1[i] == '0' && num2[i] == '1') {
            if (car == '1') {
                sum = '0' + sum;
                car = '1';
            } else
                sum = '1' + sum;
        } else {
            if (car == '1') {
                sum = '1' + sum;
                car = '1';
            } else{
                sum = '0' + sum;
                car = '1';
            }
        }
    }
    if (car == '1') {
        sum = '1' + sum;
    }
    reg_val[convert_hex_dec(ans)] = convert_bin_hex(sum);
}
void MachineSimulator ::display_memory() {
    cout << "  ";
    for (int j = 0; j < 16; ++j) {
        if (j > 9) {
            cout << setw(3) << (char)(j+55);
        } else
            cout << setw(3) << j;
    }
    cout << endl;
    for (int i = 0; i < 16; ++i) {
        if (i > 9) {
            cout << setw(2) << (char)(i+55) << " ";
        } else
            cout << setw(2) << i << " ";
        for (int j = 0; j < 16; ++j) {
            string val;
            if (i > 9 && j > 9) {
                val = dec_to_hex(i)+ dec_to_hex(j);
            }
            else if (i > 9) { val = (char)(i+55)+ to_string(j);}
            else if (j > 9) {val = to_string(i)+ (char)(j+55);}
            else
                val = to_string(i)+ to_string(j);
            cout<<' '; this -> display_mem(val);
        }
        cout << endl;
    }
}
void MachineSimulator ::display_registers() {
    for (int i = 0; i < 16; ++i) {
        cout<<'R'<<dec_to_hex(i)<<':'<<reg_val[i]<<' ';
        if(i == 7) {cout<<endl;}
    }
    cout<<endl;
}
void MachineSimulator ::run_program() {
    for (int i = 0; i <  instructions.size(); ++i) {
        string ins = instructions[i];
        if (!valid_value(ins)) {
            cout<<"INVALID INSTRUCTIONS";
            exit(0);
        }
        if (ins[0] == '1') {
            loadFromMemory(ins.substr(1,1),ins.substr(2,2));
        } else if (ins[0] == '2') {
            loadRegister(ins.substr(1,1),ins.substr(2,2));
        } else if (ins[0] == '3') {
            if (ins[2] == '0' && ins[3] == '0') {
                display_address_zero(ins.substr(1,1));
            } else
                StoreInMemory(ins.substr(1,1),ins.substr(2,2));
        }else if (ins[0] == '4') {
            copy(ins.substr(2,1),ins.substr(3,1));
        }else if (ins[0] == '5') {
            adding_2s(ins.substr(1,1),ins.substr(2,1),ins.substr(3,1));
        }else if (ins[0] == '6') {
            floating_point_addition(ins.substr(1,1),ins.substr(2,1),ins.substr(3,1));
        }else if (ins[0] == 'B') {
            int val = convert_hex_dec(ins.substr(1,1));
            if (reg_val[val] == reg_val[0]) {
                program_counter = convert_hex_dec(ins.substr(2,2));
            }
        }else if (ins[0] == 'C') {
            cout << "1- Display the status of registers\n" << "2- Display PC\n" << "3- Display IR\n" << "4- Display Memory\n"<<"5- All\n"<<"6- exit\n";
            cout << "Enter one of the choices above: "<<endl;
            int op; cin >> op;
            if (op == 1) {
                display_registers();
            } else if (op == 2) {
                cout<<"PC: "<<dec_to_hex(program_counter)<<endl;
            } else if (op == 3) {
                cout<<"IR: "<<instructions[instructions.size()-2]<<endl;
            } else if (op == 4) {
                display_memory();
            } else if (op == 5) {
                display_memory();
                display_registers();
                cout<<"PC: "<<dec_to_hex(program_counter)<<endl;
                cout<<"IR: "<<instructions[instructions.size()-2]<<endl;
            } else if (op == 6) {
                cout<<"The program is halted.";
            }
            exit(0);
        }
        program_counter += 2;
    }
} // The 'run_program' function executes a series of instructions stored in the 'instructions'
// array. Each instruction is a string that represents an operation or action in the simulator.
// The function interprets each instruction and simulates the corresponding action in the
// simulated machine.


