//
// Created by gregb on 9/22/2019.
//

#ifndef QUEUEFAMILIES_HPP
#define QUEUEFAMILIES_HPP

#include <optional>
#include <vector>

//Queue Family stuff
struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete(){
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

QueueFamilyIndices findQueueFamilies(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface){
    QueueFamilyIndices indices;
    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, nullptr);
    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, queueFamilies.data());
    int i = 0;
    VkBool32 presentSupport = false;
    for(auto const &queueFamily : queueFamilies){
        vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, i, surface, &presentSupport);

        if(queueFamily.queueCount > 0 && queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT){
            indices.graphicsFamily = i;
        }
        //In the event that the GPU has two different queues for rendering and presentation
        if(queueFamily.queueCount > 0 && presentSupport){
            indices.presentFamily = i;
        }
        //early break condition
        if(indices.isComplete())
            break;
        i++;
    }

    return  indices;
}


#endif //QUEUEFAMILIES_HPP