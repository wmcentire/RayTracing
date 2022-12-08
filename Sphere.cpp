#include "Sphere.h"

bool Sphere::Hit(const Ray& r, float tMin, float tMax, RaycastHit& hit)
{
    glm::vec3 oc = r.origin - m_center;
    float a = glm::dot(r.direction, r.direction);
    float b = 2 * glm::dot(r.direction, oc);
    float c = glm::dot(oc, oc) - (m_radius * m_radius);

    // b^2 - 4ac 
    float discriminant = (b * b) - (4 * a * c);

    // 0 - 1 hit
    // 1 = 2 hit

    if (discriminant >= 0)
    {
        float t = (-b - sqrt(discriminant)) / (2 * a);

        if (t > tMin && t < tMax)
        {
            hit.distance = t;
            hit.point = r.GetPoint(t);
            hit.normal = (hit.point - m_center) / m_radius;

            hit.material = m_material.get();

            return true;
        }

        t = (-b + sqrt(discriminant)) / (2 * a);

        if (t > tMin && t < tMax)
        {
            hit.distance = t;
            hit.point = r.GetPoint(t);
            hit.normal = (hit.point - m_center) / m_radius;

            hit.material = m_material.get();

            return true;
        }

    }

    return false;
}