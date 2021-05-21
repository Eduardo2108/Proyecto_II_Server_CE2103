//
// Created by eduardozumbadog on 21/5/21.
//
#include "BPManager.h"

BPManager *BPManager::instance{nullptr};
std::mutex BPManager::mutex_;

BPManager *BPManager::getInstance(GameSettings *settings) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (BPManager::instance == nullptr)
        instance = new BPManager(settings);
    return instance;
}