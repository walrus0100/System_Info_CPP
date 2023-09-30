#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <netdb.h>
#include <arpa/inet.h>

int main() {

    // Get system information
    struct sysinfo sys_info;
    sysinfo (&sys_info);

    std::cout << "System Information:" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Total RAM: " << sys_info.totalram / 1024 / 1024 << " MB" << std::endl;
    std::cout << "Free RAM: " << sys_info.freeram / 1024 / 1024 << " MB" << std::endl;
    std::cout << "Number of CPUs: " << sys_info.procs << std::endl;
    std::cout << "System uptime: " << sys_info.uptime / 60 / 60 << " hours" << std::endl;

    // Get hostname and IP address
    char host_name[256];
    gethostname(host_name, sizeof(host_name));
    std::cout << std::endl << "Hostname: " << host_name << std::endl;

    struct utsname uname_data;
    uname(&uname_data);
    std::cout << "Machine: " << uname_data.machine << std::endl;
    std::cout << "Kernel version: " << uname_data.release << std::endl;

    struct hostent *host_entry = gethostbyname(host_name);
    char *ip_address = inet_ntoa(*((struct in_addr*) host_entry->h_addr_list[0]));
    std::cout << "IP Address: " << ip_address << std::endl;

    return 0;
}
