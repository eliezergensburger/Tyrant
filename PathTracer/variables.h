#pragma once

constexpr static float pi = 3.1415926535897932f;

constexpr static unsigned window_width = 1920;
constexpr static unsigned window_height = 1080;

constexpr static unsigned render_width = 1920;
constexpr static unsigned render_height = 1080;

constexpr static int bvh_stack_size = 32;

constexpr static float epsilon = 0.001f;

extern glm::vec2 sun_position;
extern bool sun_position_changed;
extern int sm_cores;

enum class GeometryType {
	Sphere = 0, Triangle = 1
};

struct RayQueue {
	glm::vec3 origin;
	glm::vec3 direction;
	glm::vec3 direct;
	float distance;
	int identifier;
	int bounces;
	int index;
	GeometryType geometry_type = GeometryType::Triangle;
	bool lastSpecular = true;
};

struct ShadowQueue {
	glm::vec3 origin;
	glm::vec3 direction;
	glm::vec3 color;
	int buffer_index;
};

const unsigned int ray_queue_buffer_size = 1'048'576 * 2;
