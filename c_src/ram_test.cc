#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <filesystem>

namespace fs = std::filesystem;

void write_file(const fs::path& file_path, const std::string& content) {
    std::ofstream file(file_path, std::ios::binary);
    file.write(content.c_str(), content.size());
    file.close();
}

void ram() {
    std::string folder_name = "iloveyoudaddy";
    fs::path folder_path = folder_name;
    
    fs::create_directories(folder_path);
    
    std::vector<std::thread> threads;
    for (int i = 1; i <= 10; i++) {
        std::string file_name = folder_name + "_" + std::to_string(i) + ".txt";
        fs::path file_path = folder_path / file_name;
        
        std::string content;
        for (int j = 0; j < 10000000; j++) {
            content += "i love you daddy\n";
        }
        
        threads.emplace_back(write_file, file_path, content);
    }
    
    for (auto& thread : threads) {
        thread.join();
    }
}

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();
    
    ram();
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Time taken: " << duration.count() << " ms" << std::endl;
    
    return 0;
}
