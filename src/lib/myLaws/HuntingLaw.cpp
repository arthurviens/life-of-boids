#include "HuntingLaw.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include <vector>
#include "../../resources/model/Agent.hpp"
#include "../../resources/model/Flock.hpp"
#include "../../resources/model/Eagle.hpp"

HuntingLaw::HuntingLaw() : Law(20.f), m_manualHunting(false){};

HuntingLaw::HuntingLaw(Flock* pFlock) : Law(20.f), m_manualHunting(false) {
	m_pFlock = pFlock;
}

HuntingLaw::HuntingLaw(Flock* pFlock, bool manualHunting) : Law(20.f), m_manualHunting(manualHunting) {
	m_pFlock = pFlock;
};

Vec2 HuntingLaw::compute(Agent& currentAgent, const std::vector<Agent*>& neighbors) const {
	Vec2 newVelocity{};
	//To compute with the front of the triangle of the agent

	if (neighbors.size() > 0) {
		float weight = distance((currentAgent).getPosition(), (*neighbors[0]).getPosition());


		if (weight < currentAgent.getBodySize()*1.5) {
			(*m_pFlock).destroyAgent((*neighbors[0]).getPosition());

			if (currentAgent.getBodySize() < 26)
				currentAgent.setSize((currentAgent.getBodySize() + 5));
			else {
				currentAgent.setSize(10);
				currentAgent.setVelocity(Vec2{ 5,0 });
				Vec2 pos = currentAgent.getPosition();
				Vec2 vel = Vec2{-5,-5};

				(*m_pFlock).addAgent(new Eagle{ pos, vel,10,50,100, 15.f, Color::Red, HuntingLaw{m_pFlock, false}});
				(*m_pFlock).addAgent(new Eagle{ pos, Vec2{ 5,5 },10,50,100, 15.f, Color::Red, HuntingLaw{m_pFlock, false}});
			}
		}

		//If we are not in manual mode, we set the speed to be going to the agent's next position
		if(!m_manualHunting)
			newVelocity = (*neighbors[0]).getVelocity() + ((currentAgent).getPosition() - (currentAgent).getPosition()) * weight;
	}

	return newVelocity * m_relaxation;
};