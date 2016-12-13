#include "StorkTimApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<StorkTimApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

StorkTimApp::StorkTimApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  StorkTimApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  StorkTimApp::associateSyntax(_syntax, _action_factory);
}

StorkTimApp::~StorkTimApp()
{
}

// External entry point for dynamic application loading
extern "C" void StorkTimApp__registerApps() { StorkTimApp::registerApps(); }
void
StorkTimApp::registerApps()
{
  registerApp(StorkTimApp);
}

// External entry point for dynamic object registration
extern "C" void StorkTimApp__registerObjects(Factory & factory) { StorkTimApp::registerObjects(factory); }
void
StorkTimApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void StorkTimApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { StorkTimApp::associateSyntax(syntax, action_factory); }
void
StorkTimApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
