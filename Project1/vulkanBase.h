

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include "extensions.h"
#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"

#define VK_CHECK_RESULT(f) {																						\
	if (f != VK_SUCCESS) {std::cerr << "Fatal : VkResult is " << f << "\" in " << __FILE__ << " at line " << __LINE__ << std::endl;	\
		assert(f == VK_SUCCESS);																					\
	}																												\
}

class vulkanBase
{
public:
	vulkanBase();
	~vulkanBase();
	void run();

private:
	void initWindow();
	void initVulkan();
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();
	void setupDebugCallback();
	void createInstance();
	bool isDeviceSuitable(VkPhysicalDevice device);
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	void createSwapChain();
	void createImageView();
	void createGraphicsPipeline();
	void createRenderPass();
	void createFramebuffers();
	void createCommandPool();
	void createCommandBuffers();
	void createSemaphores();
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	void pickPhysicalDevice();
	void createLogicalDevice();
	void createSurfaceDevice();
	void mainLoop();
	void drawFrame();
	void cleanup();

	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
														VkDebugUtilsMessageTypeFlagsEXT messageType,
														const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
														void* pUserData);

	int						width			= 800;
	int						height			= 600;

	const std::vector<const char*> validationLayers = {
		"VK_LAYER_LUNARG_standard_validation"
	};

	const std::vector<const char*> deviceExtensions = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};

#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

	GLFWwindow								*window					=nullptr;
	VkInstance								instance				=VK_NULL_HANDLE;
	VkDebugUtilsMessengerEXT				MSGcallback				=VK_NULL_HANDLE;
	VkPhysicalDevice						physicalDevice			=VK_NULL_HANDLE;
	VkDevice								device					=VK_NULL_HANDLE;
	VkQueue									graphicsQueue			=VK_NULL_HANDLE;
	VkQueue									presentQueue			=VK_NULL_HANDLE;
	VkSurfaceKHR							surface					=VK_NULL_HANDLE;
	VkSwapchainKHR							swapChain				=VK_NULL_HANDLE;
	std::vector<VkImage>					swapChainImages;
	VkFormat								swapChainImageFormat;
	VkExtent2D								swapChainExtent;
	std::vector<VkImageView>				swapChainImageViews;
	VkRenderPass							renderPass				=VK_NULL_HANDLE;
	VkPipelineLayout						pipelineLayout			=VK_NULL_HANDLE;
	VkPipeline								graphicsPipeline		=VK_NULL_HANDLE;
	std::vector<VkFramebuffer>				swapChainFramebuffers;
	VkCommandPool							commandPool				=VK_NULL_HANDLE;
	std::vector<VkCommandBuffer>			commandBuffers;
	VkSemaphore								imageAvailableSemaphore;
	VkSemaphore								renderFinishedSemaphore;
};

