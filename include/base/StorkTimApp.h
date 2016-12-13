#ifndef STORK_TIMAPP_H
#define STORK_TIMAPP_H

#include "MooseApp.h"

class StorkTimApp;

template<>
InputParameters validParams<StorkTimApp>();

class StorkTimApp : public MooseApp
{
public:
  StorkTimApp(InputParameters parameters);
  virtual ~StorkTimApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* STORK_TIMAPP_H */
