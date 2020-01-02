//
// Created by Anneline Daggelinckx on 11/27/19.
//

#ifndef SPACEINVADERS_CONTROLLER_H
#define SPACEINVADERS_CONTROLLER_H

#include "Entity.h"
#include "Model.h"
#include "View.h"

namespace controller {
    /**
     * class controller from the MVC pattern
     */
    class Controller {
        std::shared_ptr<view::View> view;
        std::shared_ptr<model::Model> model;
    public:
        Controller() = default;

        /**
         * Populate model and view
         * @param model
         * @param view
         */
        Controller(std::shared_ptr<model::Model> model, std::shared_ptr<view::View> view);

        /**
         * handles event when one occured (for example user presses key)
         * @param dt
         * @param event
         */
        void handleEvent(float dt, sf::Event &event);

        /**
         * updates that have to happen every tick
         */
        void update(float dt);
    };
}


#endif //SPACEINVADERS_CONTROLLER_H
