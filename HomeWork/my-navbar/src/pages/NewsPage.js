import React from 'react';
import NewsItem from '../components/NewsItem';

const NewsPage = () => {
    const newsData = [
        {
            title: "Заголовок новини 1",
            description: "Опис новини 1. Опис новини.",
            date: "11 червня 2024"
        },
        {
            title: "Заголовок новини 2",
            description: "Опис новини 2. Опис новини.",
            date: "6 березня 2024"
        },
        {
            title: "Заголовок новини 3",
            description: "Опис новини 3. Опис новини.",
            date: "12 серпня 2024"
        }
    ];

    return (
        <div>
            <h1>Новини</h1>
            {newsData.map((news, index) => (
                <NewsItem
                    key={index}
                    title={news.title}
                    description={news.description}
                    date={news.date}
                />
            ))}
        </div>
    );
};

export default NewsPage;
