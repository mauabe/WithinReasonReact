'use strict';

var React = require("react");
var ReactDOMRe = require("reason-react/lib/js/src/ReactDOMRe.js");
var Timer$ReasonReactExamples = require("./Timer.bs.js");

ReactDOMRe.renderToElementWithId(React.createElement(Timer$ReasonReactExamples.make, { }), "root");

/*  Not a pure module */
