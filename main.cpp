#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

int main() {
    mongocxx::instance instance{}; // فقط یکبار باید مقداردهی شود
    mongocxx::client client{ mongocxx::uri{"mongodb://localhost:27017"} };

    try {
        auto db = client["test"];  // به دیتابیس `test` وصل شو
        std::cout << "✅ Connected to MongoDB successfully!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Connection failed: " << e.what() << std::endl;
    }

    return 0;
}
