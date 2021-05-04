#pragma once

#include "primitive_container.h"
#include <cgv_gl/rectangle_renderer.h>

#include "lib_begin.h"

namespace cgv {
	namespace nui {

		class CGV_API rectangle_container : public primitive_container
		{
		protected:
			cgv::render::surface_render_style srs;
			/// texture coordinate range
			std::vector<vec4> texcoord_ranges;
			/// whether to use texture coordinates
			bool use_texcoords;
			/// keep pointer of texture to be used for texturing
			std::shared_ptr<cgv::render::texture> tex;

			void prepare_render(cgv::render::context& ctx, cgv::render::renderer& r, const cgv::render::render_style& rs, const std::vector<uint32_t>* indices_ptr = 0) const;
			static int compute_intersection(
				const vec3& rectangle_center, const vec2& rectangle_extent,
				const vec3& ray_start, const vec3& ray_direction, contact_info::contact& C, contact_info::contact* C2_ptr = 0);
			static int compute_intersection(
				const vec3& rectangle_center, const vec2& rectangle_extent, const quat& rectangle_rotation,
				const vec3& ray_start, const vec3& ray_direction, contact_info::contact& C, contact_info::contact* C2_ptr = 0);
		public:
			rectangle_container(bool _use_colors, bool _use_orientations, bool _use_texcoords);
			std::string get_primitive_type() const;
			uint32_t add_rectangle(const vec3& center, const vec2& extent);
			uint32_t add_rectangle(const vec3& center, const vec2& extent, const quat& orientation);
			uint32_t add_rectangle(const vec3& center, const vec2& extent, const rgba& color);
			uint32_t add_rectangle(const vec3& center, const vec2& extent, const quat& orientation, const rgba& color);
			uint32_t add_rectangle(const vec3& center, const vec2& extent, const box2& texcoord_range);
			uint32_t add_rectangle(const vec3& center, const vec2& extent, const box2& texcoord_range, const quat& orientation);
			uint32_t add_rectangle(const vec3& center, const vec2& extent, const box2& texcoord_range, const rgba& color);
			uint32_t add_rectangle(const vec3& center, const vec2& extent, const box2& texcoord_range, const quat& orientation, const rgba& color);

			void set_texture(std::shared_ptr<cgv::render::texture> _tex) { tex = _tex; }

			quat get_rotation(uint32_t i) const { return use_orientations ? orientations[i] : quat(1.0f, 0.0f, 0.0f, 0.0f); }
			box3 compute_bounding_box() const;
			void compute_closest_point(contact_info& info, const vec3& pos);
			void compute_closest_oriented_point(contact_info& info, const vec3& pos, const vec3& normal, float orientation_weight);
			void compute_first_intersection(contact_info& info, const vec3& start, const vec3& direction);
			void compute_all_intersections(contact_info& info, const vec3& start, const vec3& direction, bool only_entry_points);
			bool init(cgv::render::context& ctx);
			void clear(cgv::render::context& ctx);
			void draw(cgv::render::context& ctx);
			const cgv::render::render_style* get_render_style() const { return &srs; }
			cgv::render::surface_render_style& ref_render_style() { return srs; }
		};
	}
}

#include <cgv/config/lib_end.h>