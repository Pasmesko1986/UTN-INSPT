// LoadingSpinner.js
import React from 'react';
import Lottie from "lottie-react";
import cloud from '../assets/lottie_animations/cloud.json';


const LoadingSpinner = () => {
  const spinnerStyle = {
    position: 'fixed',
    top: 0,
    left: 0,
    width: '100%',
    height: '100%',
    display: 'flex',
    alignItems: 'center',
    justifyContent: 'center',
    zIndex: 9999,
  };

  const blurBackgroundStyle = {
    position: 'absolute',
    top: 0,
    left: 0,
    width: '100%',
    height: '100%',
    background: 'black',
    backgroundSize: 'cover',
    filter: 'blur(14px)',
    opacity: 0.9,
  };

  const loadingTextStyle = {
    fontSize: '24px',
    color: 'white',
    fontWeight: 'bold',
    width: '80%',
    maxWidth: 450,
    padding:10
  };

  return (
    <div style={spinnerStyle}>
      <div style={blurBackgroundStyle}></div>
      <div style={loadingTextStyle} >
      <Lottie animationData={cloud} loop={true} />:
      </div>
      
    </div>
  );
};

export default LoadingSpinner;