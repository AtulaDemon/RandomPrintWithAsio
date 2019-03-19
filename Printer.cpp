#include "Printer.hpp"

Printer::Printer() {
    io_service = std::shared_ptr<asio::io_service> (new asio::io_service);
    work = std::shared_ptr<asio::io_service::work> (new asio::io_service::work(*io_service));
}

Printer::~Printer() {}


void Printer::worksForThreads() {
    io_service->run();
}

void Printer::printOneNumber(int i) {
    global_stream_lock.lock();
    std::cout << "[" <<  std::this_thread::get_id()  << "] " << __FUNCTION__  << " i = " << i <<  std::endl;
    global_stream_lock.unlock();
}

void Printer::worksOfService() {
    for(int i = 0; i <100; i++) {
        io_service -> post(std::bind(&printOneNumber, this, i));
        std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
    }
}

void Printer::run() {
    std::thread printerThreads[5];
    std::cout << "[" << std::this_thread::get_id() << "] Program start running." << std::endl;

    for(int i=0; i<5; i++) {
        printerThreads[i] = std::thread(std::bind(&worksForThreads, this));
    }

    io_service -> post(std::bind(&worksOfService, this));

    work.reset();

    for(int i=0; i<5; i++) {
        if(printerThreads[i].joinable())
            printerThreads[i].join();
    }
}
