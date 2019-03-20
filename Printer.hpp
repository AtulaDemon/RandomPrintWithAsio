#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <iostream>
#include <mutex>
#include <asio.hpp>
#include <functional>
#include <thread>
#include <random>
#include <chrono>

class Printer {
    private:
        std::mutex                                  global_stream_lock;
        std::shared_ptr< asio::io_service >         io_service;
        std::shared_ptr< asio::io_service::work >   work;

        void                                        worksForThreads();
        void                                        printOneNumber();
        void                                        worksOfService();

    public:
                                                    Printer();
                                                    ~Printer();

        void                                        run();

};

#endif //PRINTER_HPP
