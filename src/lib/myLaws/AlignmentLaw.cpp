#include "AlignmentLaw.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
#include "../../resources/model/Agent.hpp"


Vec2 AlignmentLaw::compute(Agent& currentAgent, const std::vector<Agent*>& neighbors) const {

	Vec2 nextVelocity(0, 0);
	if (neighbors.size() > 0) {
		for (int i = 0; i < neighbors.size(); ++i) {
			nextVelocity = nextVelocity + (*neighbors[i]).getVelocity();
			// std::cout << "I'm here with neighbor " << (*neighbors[i])._id << " its velocity is " << (*neighbors[i]).getVelocity() << " and nextVelocity is " << nextVelocity << '\n';
		}
		nextVelocity = nextVelocity / neighbors.size();
	}

	//std::cout << "Returning nextvelocity : " << nextVelocity << '\n';
	return nextVelocity;
};