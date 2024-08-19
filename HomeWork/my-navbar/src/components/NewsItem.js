import React from 'react';
import './NewsItem.css'; 

const NewsItem = ({ title, description, date }) => {
    return (
        <div className="news-item">
            <h2>{title}</h2>
            <p>{description}</p>
            <small>{date}</small>
        </div>
    );
};

export default NewsItem;
