import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import NavBar from './components/NavBar';
import NewsPage from './pages/NewsPage';
import LoginPage from './pages/LoginPage';
import RegisterPage from './pages/RegisterPage';
import './App.css'; 

const App = () => {
    return (
        <Router>
            <NavBar />
            <div className="container">
                <Routes>
                    <Route path="/news" element={<NewsPage />} />
                    <Route path="/login" element={<LoginPage />} />
                    <Route path="/register" element={<RegisterPage />} />
                    <Route path="/" element={<h1>Головна сторінка</h1>} />
                </Routes>
            </div>
        </Router>
    );
};

export default App;
