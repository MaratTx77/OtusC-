#include <iostream>
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>

int main() {
    std::vector<unsigned long> ip_pool;

    try {
        for (std::string line; std::getline(std::cin, line);) { // Читаем адреса как беззнаковые 4 байтные числа
            std::vector<std::string> result;
            boost::split(result, line, boost::is_any_of("\t"));
            ip_pool.push_back(boost::asio::ip::address_v4::from_string(result.at(0)).to_ulong());
        }

        std::sort(ip_pool.begin(), ip_pool.end(), std::greater<>()); // Обратная сортировка

        for(const auto& addr: ip_pool) // Печать
            std::cout << boost::asio::ip::address_v4(addr).to_string() << std::endl;

        for(const auto& addr: ip_pool) // Печать у которых 1.x.x.x
            if (addr >> 24 == 1)
                std::cout << boost::asio::ip::address_v4(addr).to_string() << std::endl;

        for(const auto& addr: ip_pool) // Печать у которых 46.70.x.x
            if (addr >> 24 == 46 && (addr >> 16 & 0xFF) == 70)
                std::cout << boost::asio::ip::address_v4(addr).to_string() << std::endl;

        for(const auto& addr: ip_pool) // Печать у которых любой байт адреса == 46
            if (addr >> 24 == 46 || (addr >> 16 & 0xFF) == 46 || (addr >> 8 & 0xFF) == 46 || (addr & 0xFF) == 46)
                std::cout << boost::asio::ip::address_v4(addr).to_string() << std::endl;

    } catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}